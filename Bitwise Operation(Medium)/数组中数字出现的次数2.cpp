#include<vector>
//����״̬������⣬������ñ���ͳ�ƣ������������ͳ���������ö����Ʊ�ʾ��ͳ�Ƹ�λ1���ֵĴ�����Ȼ��%3�Ϳ��Եõ������
//��Ϊ��������һ�����Ȼ��3�ı�������ô��λͳ��ȡ1�Ĵ���%3���� ��0�������ʱ��û���� ����Ժ���
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