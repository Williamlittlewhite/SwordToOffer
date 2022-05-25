#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//����ܼ� ���򼴿� ��׼����ǲ��ô󶥶Ѽ����ȶ��еķ������� ������ѡ
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
        for (int i = 0;i < k;i++) //ע���ж�����������q.size����Ϊpop��q.size��仯
        {
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
};
