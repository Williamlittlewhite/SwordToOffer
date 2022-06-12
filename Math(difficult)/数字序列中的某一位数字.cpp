#include<string>
using namespace std;
//本题分为3步，首先确定n对应的digit位数，利用n-=count 每成功减1次证明n的digit数位会加1  然后确定n对应第几个数 假设n=10.那么n对应第一个数
//10即start+0（start+(n-1)/digit);n=11时也符合上面规律，同属于start+0（start+(n-1)/digit)这个数
//,最后确定n对应的是该数的哪一个位 n=10对应第1位 n=11对应第二位(s[(n-1)%digit]-'0')
class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;
        long long start = 1;
        long long count = 9;    
        while (n>count)
        {
            n -= count;
            start *= 10;
            digit += 1;
            count = 9 * start * digit;
        }
        int num = start + (n - 1) / digit ;
        string s = to_string(num);
        return s[(n - 1) % digit]-'0';
    }
};