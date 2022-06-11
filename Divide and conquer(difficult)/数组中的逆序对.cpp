#include<vector>
using namespace std;
//本题想法超出时间限制，参考官方题解求解
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
//本题利用分治算法，设merge_sort为归并某个数组，然后返回该数组的逆序数(l>=r返回)，然后我们对于两个子数组实现归并，利用双指针指向两个数组首个元素
//如果某个指针已经超界，则在后续数组接上相应的剩余未超界指针的元素，否则判断tmps[i]>tmps[j]?如果大于则把小的放在nums排序数组中，使得有序
//同时返回逆序数，如果小于等于则依然把小的放在nums数组中，但不会产生逆序数
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