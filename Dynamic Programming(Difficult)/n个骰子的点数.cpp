#include<vector>
using namespace std;
//关键点在于设置f(n,x)为n个骰子投出和为x的概率=f(n-1,x-1)*1/6+f(n-1,x-2)*1/6+````+f(n-1,x-6)*1/6这样进行求和 注意(x-k)这种的边界要特殊
//设定，然后n个骰子投出的和为n——6n，因此数目为5n+1 求和得到本题答案
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<double>> dp(n+1,vector<double>(6*n+1));
        vector<double> v;
        for (int i = 1;i <= 6;i++)
            dp[1][i] = 1.0 / 6;
        for (int i = 2;i <= n;i++)
        {
            for (int j = i;j <= i * 6;j++) {
                for (int k = 1;k <= 6;k++)
                {
                    if (j - k >= 0)
                        dp[i][j] += dp[i-1][j - k] / 6;
                    else
                        break;
                }
            }
        }
        for (int i = 0;i < 5 * n + 1;i++)
            v.push_back(dp[n][n + i]);
        return v;
    }
};