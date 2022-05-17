#include<vector>
#include<queue>
using namespace std;
//�����൱��һ������ʽdp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1]�߽�����һ��Ҫ���⴦������ͨ����������
//�ķ�ʽ���Ժܼ򵥵���ɸ��� ���巽�����´�����ʾ�����εݹ����dp����ֱ�����temp[row][col],��̬�滮�ķ����ܺ���
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