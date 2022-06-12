#include<math.h>
using namespace std;
//������3**a�η����������ݵķ�Χ���������Ҫ���ѭ�����ݷ�����⣬�����ģ���������ʾ���У�Ȼ�������ѧ�Ƶ�3Ϊ������һ��Ϊ1
//��3+1=2+2��Ϊ2�򲻴���Ϊ0Ҳ�������⴦��
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
    //# ��(x^ a) % p ���� ����������
    //def remainder(x, a, p) :
    //    rem = 1
    //    while a > 0:
    //       if a % 2 : rem = (rem * x) % p
    //       x = x * *2 % p
    //       a //= 2
    //    return rem

    
};