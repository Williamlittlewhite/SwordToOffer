#include<vector>
using namespace std;
//本题比较简单，利用数组下标存取信息即可，注意特殊情况就是输入
//0,1其实暗含数组应该有3个，故j应该在判断时候+1！本题大家解法也都是二分
//查找有序数组优先考虑二分查找，但是遍历的思路更容易理解！
class Solution {
public:
    int count[10000]={0};
    int missingNumber(vector<int>& nums) {
        int temp = 1;
        for (int i = 0;i < nums.size();i++)
            count[nums[i]]++;
        for (int j = 0;j < int(nums.size())+1;j++)
            if (count[j] == 0)
                temp=j;
        return temp;
    }
};