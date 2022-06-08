#include<queue>
using namespace std;
//��������dequeά��һ�������ݼ��Ķ��У�ȡ���ֵ����ǰ��popfront���ɣ��Ӻ���push��ʱ��ע��ά�ֵ�����
//queueά��һ����ͨ�Ķ��У�Ϊ����ʾ������popfront�ķ���ֵ��ͬʱע��pop frontʱ��������������ֵ����ôdeque����Ķ���ҲҪɾ��
class MaxQueue {
public:
    deque<int> d;
    queue<int> q;
    MaxQueue() {

    }

    int max_value() {
        if (d.empty())return -1;
        return d.front();
    }

    void push_back(int value) {
        q.push(value);
        while (!d.empty() && d.back() < value)
        {
            d.pop_back();
        }
        d.push_back(value);
    }

    int pop_front() {
        if (q.empty())return -1;
        int ans = q.front();
        if (ans == d.front())
            d.pop_front();
        q.pop();
        return ans;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */