#include<vector>
#include<algorithm>
using namespace std;
//暴力搜索超出时间限制 考虑动态规划
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        if (prices.empty())
//            return 0;
//        int ans = 0;
//        for (int i = 0;i < prices.size();i++)
//        {
//            for (int j = i; j < prices.size();j++)
//            {
//                ans = max(ans, prices[j] - prices[i]);
//            }
//        }
//
//        return ans;
//    }
//};
//股票的前i天的最大利益dp[i]等于max(前i-1天的最大利益，第i天的价格-前i-1天的最低价格) 利用这个递推公式就可以了
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        vector<int> dp(prices.size());
        dp[0]=0;
        for (int i = 1;i < prices.size();i++)
            dp[i] = max(dp[i - 1], prices[i] - (*min_element(prices.begin(), prices.begin()+i)));
        return *max_element(dp.begin(),dp.end());
    }
};
//优化版本
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int profit =0;
        int cost = INT_MAX;
        for (int i = 0;i < prices.size();i++)
        {
            cost = min(cost, prices[i]);
            profit = max(profit, prices[i] - cost);
        }
            return profit;
    }
};