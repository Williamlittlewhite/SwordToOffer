#include<vector>
using namespace std;
//本题很简单，利用数组的索引就可以进行求解，数组的索引作为其中的信息参与解题
class Solution {
private:
    int count[100000]={0};
public:
    int findRepeatNumber(vector<int>& nums) {
        int temp = -1;
        for (int i = 0;i < nums.size();i++)
        {
            count[nums[i]]++;
        }
        for (int j = 0;j < 100000;j++)
        {
            if (count[j] > 1)
            {
                temp=j;
                break;
            }
        }
        return temp;
    
    }
};