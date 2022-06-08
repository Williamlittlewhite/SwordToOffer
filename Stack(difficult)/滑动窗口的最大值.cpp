#include<vector>
#include<algorithm>
using namespace std;
//�漰�������ֵӦ���뵽���ȶ��е���ⷽ�����ٷ����ο�ע��
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
//���ߣ�LeetCode - Solution
//���ӣ�https ://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/hua-dong-chuang-kou-de-zui-da-zhi-by-lee-ymyo/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
// �����õ��ǵ������н��������㣬����deque����
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
//���ߣ�LeetCode - Solution
//���ӣ�https ://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/hua-dong-chuang-kou-de-zui-da-zhi-by-lee-ymyo/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������