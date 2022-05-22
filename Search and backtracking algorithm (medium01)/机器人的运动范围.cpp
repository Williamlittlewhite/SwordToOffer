#include<iostream>
#include<vector>
using namespace std;
//本题类似矩阵中路径的问题，都是dfs（也可以bfs），首先对0,0作为起始递归状态，题目较难
//由于本题的可行解都可以通过向右移动和向下移动来得到，因此只需要让visit[i][j]|=visit[i-1][j]orvisit[i][j-1]即可
//递归边界是visit[0][0]或者超过了k值 则不做任何处理进入下一次循环
//过程中记录visit[m][n]矩阵中为1的数即可
class Solution {
private:
    
    int sum(int x) {
        int s = 0;
        while (x!=0)
        {
            s += x % 10;
            x /= 10;
        }
        return s;
    }
 
public:
    int movingCount(int m, int n, int k) {
        if (k == 0)return 1;
        vector<vector<int>> visit(m, vector<int>(n, 0));
        visit[0][0] = 1;
        int count = 1;
        for(int i=0;i<m;i++)
        {
            for (int j = 0;j < n;j++) {
                if ((i == 0&&j==0)|| sum(i) + sum(j) > k)
                    continue;
                if (i - 1 >= 0) visit[i][j] |= visit[i - 1][j];
                if (j - 1 >= 0) visit[i][j] |= visit[i][j - 1];
                count += visit[i][j];
            }
        }

       return count;
    }
};