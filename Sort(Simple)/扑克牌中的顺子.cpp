#include<vector>
#include<algorithm>
using namespace std;
//����ؼ�������ʶ�����˳�ӵĳ������������:5���ƻ��಻�ظ�����С�����⣩;5������������С���С��5(��������С����0)
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