#include<vector>
using namespace std;
//���ȿ�����һ����ͬ����������������ȵ�ʱ�����Ϊ0�����õ��ľ��Ǹò�ͬ����������������Ļ������õ��ľ���������ͬ�����
//���ݵõ��Ľ�����ҵ��������е�һ��Ϊ1��λ��Ȼ��������λ��������ͬ�������ֵ���������������ǵõ�������
//��ÿ���������򼴵õ����ս����
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int temp = 0;
        for (int i : nums)
            temp ^= i;
        int div = 1;
        while ((div&temp)==0)
        {
            div <<= 1;
        }
        int a = 0, b = 0;
        for (int j : nums)
        {
            if (j & div)
                a ^= j;
            else
                b ^= j;
        }
        vector<int> v{ a, b };
        return v;
    }
};