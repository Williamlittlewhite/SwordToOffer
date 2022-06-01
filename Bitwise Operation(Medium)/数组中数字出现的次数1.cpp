#include<vector>
using namespace std;
//首先考虑找一个不同的数，当其他数相等的时候异或为0，最后得到的就是该不同的数，如果有两个的话，最后得到的就是两个不同数异或
//根据得到的结果，找到最后异或中第一个为1的位，然后根据这个位将两个不同的数划分到两个组里，进而我们得到两个组
//对每个组进行异或即得到最终结果！
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int temp = 0;
        for (int i : nums)
            temp ^= i;
        int div = 1;
        while ((div&temp)==0)
        {
            div <<= 1;
        }
        int a = 0, b = 0;
        for (int j : nums)
        {
            if (j & div)
                a ^= j;
            else
                b ^= j;
        }
        vector<int> v{ a, b };
        return v;
    }
};