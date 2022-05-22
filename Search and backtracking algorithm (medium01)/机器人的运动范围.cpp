#include<iostream>
#include<vector>
using namespace std;
//�������ƾ�����·�������⣬����dfs��Ҳ����bfs�������ȶ�0,0��Ϊ��ʼ�ݹ�״̬����Ŀ����
//���ڱ���Ŀ��нⶼ����ͨ�������ƶ��������ƶ����õ������ֻ��Ҫ��visit[i][j]|=visit[i-1][j]orvisit[i][j-1]����
//�ݹ�߽���visit[0][0]���߳�����kֵ �����κδ��������һ��ѭ��
//�����м�¼visit[m][n]������Ϊ1��������
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