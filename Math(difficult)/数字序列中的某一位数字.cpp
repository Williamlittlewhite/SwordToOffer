#include<string>
using namespace std;
//�����Ϊ3��������ȷ��n��Ӧ��digitλ��������n-=count ÿ�ɹ���1��֤��n��digit��λ���1  Ȼ��ȷ��n��Ӧ�ڼ����� ����n=10.��ôn��Ӧ��һ����
//10��start+0��start+(n-1)/digit);n=11ʱҲ����������ɣ�ͬ����start+0��start+(n-1)/digit)�����
//,���ȷ��n��Ӧ���Ǹ�������һ��λ n=10��Ӧ��1λ n=11��Ӧ�ڶ�λ(s[(n-1)%digit]-'0')
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