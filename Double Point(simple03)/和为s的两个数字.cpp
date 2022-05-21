#include <vector>
using namespace std;
//¼òµ¥µÄË«Ö¸Õë ÃëÉ±
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        vector<int> v;
        while (i<j)
        {
            if (nums[i] + nums[j] < target)
                i++;
            else if (nums[i] + nums[j] > target)
                j--;
            else
                break;
        }
        v.push_back(nums[i]);v.push_back(nums[j]);
        return v;
    }
};