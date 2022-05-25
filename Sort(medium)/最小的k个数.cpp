#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//本题很简单 排序即可 标准题解是采用大顶堆即优先队列的方法求解的 面试首选
//class Solution {
//public:
//    vector<int> getLeastNumbers(vector<int>& arr, int k) {
//        sort(arr.begin(), arr.end());
//        vector<int> v;
//        for (int i = 0;i < k;i++)
//            v.push_back(arr[i]);
//        return v;
//    }
//};
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> q;
        vector<int> v;
        if (k == 0)
            return v;
        for (int i = 0;i < k;i++)
            q.push(arr[i]);
        for (int i = k;i < arr.size();i++)
        {
            if (arr[i] < q.top())
            {
                q.pop();
                q.push(arr[i]);
            }
        }
        for (int i = 0;i < k;i++) //注意判断条件不能用q.size，因为pop后q.size会变化
        {
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
};
