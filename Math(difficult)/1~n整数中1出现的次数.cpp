#include<algorithm>
using namespace std;
//�����ѵ������Ƴ�ÿ����λ1�ļ��㹫ʽ��ԭ�������԰�λΪ�������λ����1����Ϊn//1000*100+min(100,max(n%1000-100+1,0))�ɴ˿����Ƴ�
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