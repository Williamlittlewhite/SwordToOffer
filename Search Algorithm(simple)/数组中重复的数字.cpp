#include<vector>
using namespace std;
//����ܼ򵥣���������������Ϳ��Խ�����⣬�����������Ϊ���е���Ϣ�������
class Solution {
private:
    int count[100000]={0};
public:
    int findRepeatNumber(vector<int>& nums) {
        int temp = -1;
        for (int i = 0;i < nums.size();i++)
        {
            count[nums[i]]++;
        }
        for (int j = 0;j < 100000;j++)
        {
            if (count[j] > 1)
            {
                temp=j;
                break;
            }
        }
        return temp;
    
    }
};