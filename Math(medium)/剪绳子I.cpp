//��������ѧ�Ƶ������ȸ����������β���ʽ�Ƴ����ֵ�ʱ����ȣ�Ȼ���������Ƴ�פ��õ�����Ϊ3��ʱ�������ֵ����ʱ���ʣ�೤��Ϊ2�����
//���� ��Ϊ2>1*1 ���ʣ��Ϊ1 ���ó�һ��3 ���2*2>1*3
#include<math.h>
using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        int a = 0, b = 0;
        if (n <= 3)
            return n - 1;
        else
        {
            a = n / 3;
            b = n % 3;
        }
        if (b == 0)
            return pow(3, a);
        if (b == 1)
            return pow(3, a - 1) * 2 * 2;
        return pow(3, a) * b;
    }
};