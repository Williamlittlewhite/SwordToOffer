#include<vector>
#include<algorithm>
using namespace std;
//������������ʱ������ ���Ƕ�̬�滮
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
//��Ʊ��ǰi����������dp[i]����max(ǰi-1���������棬��i��ļ۸�-ǰi-1�����ͼ۸�) ����������ƹ�ʽ�Ϳ�����
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
//�Ż��汾
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