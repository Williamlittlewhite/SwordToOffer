#include<vector>
#include<algorithm>
using namespace std;
//本题关键点是意识到组成顺子的充分条件有两个:5张牌互相不重复（大小王除外）;5张牌中最大和最小相差小于5(不包括大小王即0)
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int joker=0;
        for (int i = 0;i < nums.size() - 1;i++)
        {
            if (nums[i] == 0)
                joker++;
            else if (nums[i] == nums[i + 1])
                return false;
        }
        return nums[nums.size()-1]-nums[joker]<5;
    }
};