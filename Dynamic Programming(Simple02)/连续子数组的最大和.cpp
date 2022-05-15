#include<vector>
#include<algorithm>
using namespace std;
//本题比较简单，多次做过这种题，考虑到如果有正数的话，那么最大值一定是从0开始加的 没有正数的话直接输出最大值即可 其实就是动规思想
//如果以第i-1个数结尾的最大子数组和dp[i-1]>0那么dp[i]就考虑将dp[i-1]+nums[i]作为最大和有可能使得后续和更大，如果dp[i-1]小于0 那么
// 直接把nums[i]作为dp[i]的以第i数结尾最大子数组和即可！而且本题可以直接在原数组操作节省空间
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0, max = *max_element(nums.begin(),nums.end());
        if (max < 0)
            return max;
        for (int i = 0;i < nums.size();i++)
        {
            sum += nums[i];
            if (sum < 0)
                sum = 0;
            if (sum > max)
                max = sum;
        }
        return max;
    }
};