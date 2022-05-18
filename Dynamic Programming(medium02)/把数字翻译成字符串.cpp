#include <vector>
using namespace std;
//动态规划的想法，青蛙跳台阶和斐波那契数列的变种，定义dp[i]为从各位起第i个数字所拥有的翻译数，由于本题动规划
//数组是对称的我们从右往左进行遍历翻译和从左往右翻译规律都是一样的，由于输入是数字，我们从右往左考虑
// 进一步有当两个数字组成的值在10~25之间dp[1]=1,dp[2]=2，因此
//我们可以求解dp[0]=1 符合斐波那契数列规律 
//利用动规划dp[i]=dp[i-1]+dp[i-2]以及dp[i]=dp[i-1]进行求解即可
class Solution {
public:
    int translateNum(int num) {
        vector<int> dp(10000);
        dp[0]=1;
        dp[1]=1;
        int i = 2;
        int temp1 = num % 10;
        while (num!=0)
        {
            num /= 10;
            int temp2 = num % 10;
            if (temp1 + 10*temp2 <= 25 && temp1 +10*temp2 >= 10)
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
            temp1 = temp2;
            i += 1;
        }
        return dp[i - 1];
    }
};