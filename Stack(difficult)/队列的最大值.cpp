#include<queue>
using namespace std;
//本题利用deque维护一个单调递减的队列，取最大值即从前面popfront即可，从后面push的时候注意维持单调性
//queue维护一个普通的队列，为了显示正常的popfront的返回值，同时注意pop front时候如果正好是最大值，那么deque里面的队首也要删除
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