#include<vector>
using namespace std;
//����Ƚϼ򵥣����������±��ȡ��Ϣ���ɣ�ע�����������������
//0,1��ʵ��������Ӧ����3������jӦ�����ж�ʱ��+1�������ҽⷨҲ���Ƕ���
//���������������ȿ��Ƕ��ֲ��ң����Ǳ�����˼·��������⣡
class Solution {
public:
    int count[10000]={0};
    int missingNumber(vector<int>& nums) {
        int temp = 1;
        for (int i = 0;i < nums.size();i++)
            count[nums[i]]++;
        for (int j = 0;j < int(nums.size())+1;j++)
            if (count[j] == 0)
                temp=j;
        return temp;
    }
};