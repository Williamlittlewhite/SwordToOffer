#include<vector>
using namespace std;
//�����뷨����ʱ�����ƣ��ο��ٷ�������
//class Solution {
//public:
//    int reversePairs(vector<int>& nums) {
//        int count = 0;
//        for (int i = 0;i < nums.size();i++)
//        {
//            for (int j = i+1;j < nums.size();j++)
//            {
//                if (nums[j] < nums[i])count++;
//            }
//        }
//        return count;
//    }   
//};
//�������÷����㷨����merge_sortΪ�鲢ĳ�����飬Ȼ�󷵻ظ������������(l>=r����)��Ȼ�����Ƕ�������������ʵ�ֹ鲢������˫ָ��ָ�����������׸�Ԫ��
//���ĳ��ָ���Ѿ����磬���ں������������Ӧ��ʣ��δ����ָ���Ԫ�أ������ж�tmps[i]>tmps[j]?����������С�ķ���nums���������У�ʹ������
//ͬʱ���������������С�ڵ�������Ȼ��С�ķ���nums�����У����������������
class Solution {
private:
    int res = 0;
    int merge_sort(int l, int r, vector<int>& nums, vector<int>& tmps) {
        int m = (l + r) / 2;
        if (l >= r)return 0;
        res = merge_sort(l, m, nums, tmps) + merge_sort(m + 1, r, nums, tmps);
        for (int i = l;i <= r;i++)
            tmps[i] = nums[i];

        int i = l, j = m + 1;

        for (int k = l;k <= r;k++) {

            if (i == m + 1)
            {
                while (k <= r)
                {
                    nums[k++] = tmps[j++];
                }
                break;

            }
            else if (j == r + 1)
            {
                while (k <= r)
                {
                    nums[k++] = tmps[i++];
                }
                break;
            }

            else if (tmps[i] <= tmps[j])
                nums[k] = tmps[i++];

            else if (tmps[i] > tmps[j])
            {
                nums[k] = tmps[j++];
                res += m - i + 1;
            }
        }
        return res; 
    }
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmps(nums.size());
        return merge_sort(0, nums.size() - 1, nums, tmps);
    }
};