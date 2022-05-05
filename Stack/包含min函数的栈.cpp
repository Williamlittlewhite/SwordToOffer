    #include<stack>
    #include<algorithm>
    using namespace std;
    //本题重点是考虑栈解题优先考虑两栈并用，因为数据结构相似更好做，本题思路利用辅助栈提前压入INT的最大值，如果压入
    //栈中的元素小于此，则也压入辅助栈，后续压入元素均与辅助栈相比，如果小于则重复上述操作，如果大于则压入主栈同时
    //把辅助栈栈顶元素也压进去就可以啦，不断重复上述操作就可以实现找到最小值的原理，注意一定是INT的最大值，否则最后一个
    //测试点不会通过，题解默认最小值不超过INT_MAX，如果没用INT_MAX最后一个测试点过不了！！
    class MinStack {
    private:
        stack<int> mainstack,helpstack;
 
    public:
        /** initialize your data structure here. */
        MinStack() {
            helpstack.push(INT_MAX);
        }

        void push(int x) {
            mainstack.push(x);
            if (x < helpstack.top())
                helpstack.push(x);
            else
                helpstack.push(helpstack.top());
        }

        void pop() {
            mainstack.pop();
            helpstack.pop();
        }

        int top() {
            return mainstack.top();
        }

        int min() {
            return helpstack.top();
        }
    };

    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(x);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->min();
     */