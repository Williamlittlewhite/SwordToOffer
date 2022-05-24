#include<vector>
#include<string>
using namespace std;
//本题利用字符串的比较解决即x+y<y+x那么证明字符串x是小于y的字符串s应该放在前面，反之亦然 这样才能把数组排成最小的
//快速排序首先默认最左边为key值，设置左右哨兵，如果最左为key那么一定右面哨兵先动找到小于key的索引，再继续找左面哨兵大于key的，交换两者
//重复上述过程直到哨兵相遇，交换相遇位置和key值，然后递归排左右两边的子数组即可
//最后加起来排好序的字符串容器即可
//注意左右哨兵的左右位置必须用形参的l和r表示！
class Solution {
private:
    void QuickSort(vector<string>& strs, int l, int r) {
        if (l >= r)return;
        int i = l;int j = r;
        while (i<j)
        {
            while (strs[j] + strs[l] >= strs[l] + strs[j]&&i<j)j--;
            while (strs[i] + strs[l] <= strs[l] + strs[i]&&i<j)i++;
            swap(strs[i], strs[j]);
        }
        swap(strs[j], strs[l]);
        QuickSort(strs, l, i - 1);
        QuickSort(strs, i + 1, r);
    }
public:
    string minNumber(vector<int>& nums) {
        vector<string> strings;
        string res;
        for (int i = 0;i < nums.size();i++)
            strings.push_back(to_string(nums[i]));
        QuickSort(strings, 0, strings.size() - 1);
        for (auto    s : strings)
            res.append(s);
        return res;
    }
};