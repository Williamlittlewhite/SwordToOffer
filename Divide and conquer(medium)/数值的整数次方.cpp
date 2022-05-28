#include<algorithm>
using namespace std;
//本题利用快速幂的递归求解，首先判断n的正负，正就正常求解，负数就求解1/QuickMult(x,-n) 
//QucikMult是快速幂，首先将n/2除到1为止  利用x*x=x^2 x^2*x^2=x^4这种疯狂求解
//如果n为奇数则返回y*y*x 否则返回y*y  y=QuickMult(x,n/2)      QuickMult(x,1)=QuickMult(x,0)*QuickMult(x,0)*x=x
//注意要用long long 类型求解 因为int类型正数会比负数少一个！
class Solution {
public:
    double QuickMult(double x, long long n) {
        if (n == 0)
            return 1.0;
        double y = QuickMult(x, n / 2);
        if (n % 2 == 0)
            return y * y;
        return y * y * x;
    }
    double myPow(double x, int n) {
        long long N = n;
        if (n >= 0)
            return QuickMult(x, N);
        return 1 / QuickMult(x, -N);
    }
};
//还有一种是迭代法 利用二进制转化的思想 即把n转化为二进制 然后只有1的部分对于整数次方有贡献  可以简化空间复杂度
class Solution {
public:
    double QuickMult(double x, long long n) {
        double contribution_x = x;
        double ans = 1.0;
        while (n>0)
        {
            if (n % 2 == 1)
                ans*=contribution_x;
            contribution_x *= contribution_x;
            n /= 2;
        }
        return ans;
    }
    double myPow(double x, int n) {
        long long N = n;
        if (n >= 0)
            return QuickMult(x, N);
        return 1 / QuickMult(x, -N);
    }
};