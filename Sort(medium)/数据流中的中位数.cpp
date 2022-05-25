#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
//�Լ���д������ʱ�����Ʋο��ٷ���⣬�������ȶ��еķ�ʽ��(�󶥶Ѻ�С���ѽ��ʹ�õķ�ʽ�������)
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
    priority_queue<int,vector<int>,less<int>> maxheap;  //�����󶥶�Ҫ��ô�� less��ʾС�ڶѶ�
    priority_queue<int,vector<int>, greater<int>> minheap;//����С���� greater������ڶѶ�
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