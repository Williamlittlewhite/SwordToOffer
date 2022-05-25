#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
//自己的写法超出时间限制参考官方题解，采用优先队列的方式即(大顶堆和小顶堆结合使用的方式求解问题)
//class MedianFinder {
//private:
//    vector<double> v;
//public:
//    /** initialize your data structure here. */
//    MedianFinder() {
//        
//    }
//
//    void addNum(int num) {
//        v.push_back(num);
//    }
//
//    double findMedian() {
//        sort(v.begin(), v.end());
//        if (v.size() % 2 == 0)
//            return (v[v.size() / 2] + v[v.size() / 2 - 1])/2;
//        else
//            return v[v.size() / 2];
//    }
//};
class MedianFinder {
private:
    priority_queue<int,vector<int>,less<int>> maxheap;  //建立大顶堆要这么建 less表示小于堆顶
    priority_queue<int,vector<int>, greater<int>> minheap;//建立小顶堆 greater代表大于堆顶
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (maxheap.size() == minheap.size())
        {
            minheap.push(num);
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else
        {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }

    double findMedian() {
        if (maxheap.size()== minheap.size())
            return (maxheap.top() + minheap.top()) / 2.0;
        else
            return maxheap.top();
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */