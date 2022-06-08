#include<vector>
#include<algorithm>
using namespace std;
//涉及到求最大值应该想到优先队列的求解方法，官方题解参看注释
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return {};
        vector<int> v;
        int max = -999999;
        for (int i = 0;i < nums.size() - k+1;i++)
        {
            for (int j = i;j < i + k;j++)
            {
                if (nums[j] > max)
                {
                    max = nums[j];
                }
            }
            v.push_back(max);
            max = -9999999;
        }
        return v;
    }
   
};
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        int n = nums.size();
//        priority_queue<pair<int, int>> q;
//        for (int i = 0; i < k; ++i) {
//            q.emplace(nums[i], i);
//        }
//        vector<int> ans = { q.top().first };
//        for (int i = k; i < n; ++i) {
//            q.emplace(nums[i], i);
//            while (q.top().second <= i - k) {
//                q.pop();
//            }
//            ans.push_back(q.top().first);
//        }
//        return ans;
//    }
//};
//
//作者：LeetCode - Solution
//链接：https ://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/hua-dong-chuang-kou-de-zui-da-zhi-by-lee-ymyo/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// 这里用的是单调队列进行求解计算，利用deque处理
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        int n = nums.size();
//        deque<int> q;
//        for (int i = 0; i < k; ++i) {
//            while (!q.empty() && nums[i] >= nums[q.back()]) {
//                q.pop_back();
//            }
//            q.push_back(i);
//        }
//
//        vector<int> ans = { nums[q.front()] };
//        for (int i = k; i < n; ++i) {
//            while (!q.empty() && nums[i] >= nums[q.back()]) {
//                q.pop_back();
//            }
//            q.push_back(i);
//            while (q.front() <= i - k) {
//                q.pop_front();
//            }
//            ans.push_back(nums[q.front()]);
//        }
//        return ans;
//    }
//};
//
//作者：LeetCode - Solution
//链接：https ://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/hua-dong-chuang-kou-de-zui-da-zhi-by-lee-ymyo/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。