#include<vector>
using namespace std;
//本题很简单，就是一个数组的遍历查找，进阶要用二分查找的方法找到第一个大于等于target的leftindex再
//找到一个大于target的索引-1为rightindex，则个数为rightindex-leftindex+1

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