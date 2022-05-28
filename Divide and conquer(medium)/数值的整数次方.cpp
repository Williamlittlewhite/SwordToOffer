#include<algorithm>
using namespace std;
//�������ÿ����ݵĵݹ���⣬�����ж�n������������������⣬���������1/QuickMult(x,-n) 
//QucikMult�ǿ����ݣ����Ƚ�n/2����1Ϊֹ  ����x*x=x^2 x^2*x^2=x^4���ַ�����
//���nΪ�����򷵻�y*y*x ���򷵻�y*y  y=QuickMult(x,n/2)      QuickMult(x,1)=QuickMult(x,0)*QuickMult(x,0)*x=x
//ע��Ҫ��long long ������� ��Ϊint����������ȸ�����һ����
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
//����һ���ǵ����� ���ö�����ת����˼�� ����nת��Ϊ������ Ȼ��ֻ��1�Ĳ��ֶ��������η��й���  ���Լ򻯿ռ临�Ӷ�
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