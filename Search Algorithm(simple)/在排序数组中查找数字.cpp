#include<vector>
using namespace std;
//����ܼ򵥣�����һ������ı������ң�����Ҫ�ö��ֲ��ҵķ����ҵ���һ�����ڵ���target��leftindex��
//�ҵ�һ������target������-1Ϊrightindex�������Ϊrightindex-leftindex+1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int temp = 0;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] == target)
                temp++;
        }
        return temp;
    }
};