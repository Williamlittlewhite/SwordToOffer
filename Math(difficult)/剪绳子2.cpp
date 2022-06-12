#include<math.h>
using namespace std;
//本题是3**a次方超出了求幂的范围，因此我们要设计循环求幂法来求解，其具体模板可如下所示背诵，然后就是数学推导3为最大，最后一段为1
//则3+1=2+2，为2则不处理，为0也不做特殊处理
class Solution {
private:
    const int p = 1000000007;
public:
    int cuttingRope(int n) {
        if (n <= 3)return n - 1;
        int a = n / 3;
        int b = n % 3;
        int res;
        if (b == 2)res = remainder(3,a,p)*2%p;
        if (b == 1)res = remainder(3,a-1,p)*4%p;
        if (b == 0)res = remainder(3,a,p)%p;
        return res;
    }

    long long remainder(int x, int a, int p)
    {
        long long rem = 1;
        for (int i = 0;i < a;i++)
            rem = (rem * x) % p;
        return rem;
    }
    //# 求(x^ a) % p —— 快速幂求余
    //def remainder(x, a, p) :
    //    rem = 1
    //    while a > 0:
    //       if a % 2 : rem = (rem * x) % p
    //       x = x * *2 % p
    //       a //= 2
    //    return rem

    
};