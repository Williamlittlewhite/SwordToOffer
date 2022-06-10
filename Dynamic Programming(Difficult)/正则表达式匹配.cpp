#include<string>
#include<vector>
using namespace std;
//本题是动规的困难题目，主要是状态的定义dp[i][j]定义为s的前i个字符和p的前j个字符能否完全匹配  空字符串完全匹配 
//初始化状态主要是dp[0][0]dp[0][2]dp[0][j]等偶数的初始化如果p[j-1]=='*'那么直接继承true
//状态转移:需要注意，由于 dp[0][0] 代表的是空字符的状态， 因此 dp[i][j] 对应的添加字符是 s[i - 1] 和 p[j - 1] 。

//当 p[j - 1] = '*' 时， dp[i][j] 在当以下任一情况为 truetrue 时等于 truetrue ：
//
//dp[i][j - 2]： 即将字符组合 p[j - 2] * 看作出现 0 次时，能否匹配；
//dp[i - 1][j] 且 s[i - 1] = p[j - 2]: 即让字符 p[j - 2] 多出现 1 次时，能否匹配；
//dp[i - 1][j] 且 p[j - 2] = '.' : 即让字符 '.' 多出现 1 次时，能否匹配；
//当 p[j - 1] != '*' 时， dp[i][j] 在当以下任一情况为 truetrue 时等于 truetrue ：
//
//dp[i - 1][j - 1] 且 s[i - 1] = p[j - 1]： 即让字符 p[j - 1] 多出现一次时，能否匹配；
//dp[i - 1][j - 1] 且 p[j - 1] = '.'： 即将字符.看作字符 s[i - 1] 时，能否匹配；

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1;
        int n = p.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;//两个空字符串一定匹配
        //初始化，当p的第j-1个为*那么dp[0][j]与dp[0][j-2]的真值维持相同情况
        for (int j = 2;j < n;j+=2)
            dp[0][j] = dp[0][j - 2]&&p[j-1]=='*';
        for (int i = 1;i < m;i++) {
            for (int j = 1;j < n;j++) {
                if (p[j - 1] == '*') {
                    if (dp[i][j - 2])dp[i][j] = true;
                    else if (dp[i - 1][j] && s[i - 1] == p[j - 2])dp[i][j] = true;
                    else if (dp[i - 1][j] && p[j - 2] == '.')dp[i][j] = true;
                }
                else
                {
                    if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1])dp[i][j] = true;
                    else if (dp[i - 1][j - 1] && p[j - 1] == '.')dp[i][j] = true;
                }
            }
        }
        return dp[m-1][n-1];
    }
};