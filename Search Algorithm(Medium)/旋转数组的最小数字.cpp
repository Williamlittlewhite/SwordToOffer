#include<vector>
using namespace std;
//本题很简单抓住反转数组的特点即可，考虑到有序数组，官方题解采用二分查找求解，
// 不用二分查找面试官请你滚回家，有序数组的查找一定想二分查找！
//class Solution {
//public:
//    int minArray(vector<int>& numbers) {
//        for (int i = 0;i < numbers.size() - 1;i++)
//            if (numbers[i] > numbers[i + 1])
//                return numbers[i + 1];
//        return numbers[0];
//    }
//};
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0;int high = numbers.size()-1;
        while (low <= high)
        {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] > numbers[high])
                low = pivot + 1;
            else if (numbers[pivot] < numbers[high])
                high = pivot;
            else
                high--;
        }
        return numbers[low];
    }
};