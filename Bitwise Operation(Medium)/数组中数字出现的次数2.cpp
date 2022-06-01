#include<vector>
//有限状态机难理解，本题采用遍历统计，本题核心在于统计所有数用二进制表示后统计各位1出现的次数，然后%3就可以得到结果了
//因为有三个数一样则必然是3的倍数，那么各位统计取1的次数%3即可 而0对于求和时候没有用 则可以忽略
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int counts[32]={0};
        for (int i : nums)
        {
            for (int j = 0;j < 32;j++)
            {
                counts[j] += i & 1;
                i >>= 1;
            }
        }
        for (int k = 0;k < 32;k++)
            counts[k] %= 3;
        int sum = 0;
        for (int m = 0;m < 32;m++)
            sum += counts[m]*pow(2, m);
        return sum;
    }
};