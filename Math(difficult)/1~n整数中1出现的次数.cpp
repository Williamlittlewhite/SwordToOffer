#include<algorithm>
using namespace std;
//本题难点在于推出每个数位1的计算公式，原理如下以百位为例子其百位出现1个数为n//1000*100+min(100,max(n%1000-100+1,0))由此可以推出
//n//10^(k+1)*10^k+min(10^k,max(n%10^(k+1)-10^k+1,0))
class Solution {
public:
    int countDigitOne(int n) {
        long long multk = 1;
        int ans = 0;
        for (int k = 0;n >= multk;k++)
        {
            ans += n / (multk * 10) * multk + min(multk, max(n % (multk * 10) - multk + 1, 0LL));
            multk *= 10;
        }
        return ans;
    }
};