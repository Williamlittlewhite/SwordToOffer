#include<vector>
#include<queue>
using namespace std;
//本题相当于一个递推式dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1]边界条件一般要特殊处理，但是通过扩容数组
//的方式可以很简单的完成该题 具体方法如下代码所示，依次递归更新dp数组直到求得temp[row][col],动态规划的方法很好用
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int i=1, j=1;
        int col = grid[0].size();
        vector<vector<int>> temp(row + 1, vector<int>(col + 1,0));
        for (i = 1;i <= row;i++) {
            for (j = 1;j <= col;j++) {
                temp[i][j] = max(temp[i - 1][j], temp[i][j - 1]) + grid[i-1][j-1];
            }
        }
        return temp[row][col];
    }
};