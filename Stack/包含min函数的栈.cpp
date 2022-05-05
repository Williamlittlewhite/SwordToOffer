    #include<stack>
    #include<algorithm>
    using namespace std;
    //�����ص��ǿ���ջ�������ȿ�����ջ���ã���Ϊ���ݽṹ���Ƹ�����������˼·���ø���ջ��ǰѹ��INT�����ֵ�����ѹ��
    //ջ�е�Ԫ��С�ڴˣ���Ҳѹ�븨��ջ������ѹ��Ԫ�ؾ��븨��ջ��ȣ����С�����ظ��������������������ѹ����ջͬʱ
    //�Ѹ���ջջ��Ԫ��Ҳѹ��ȥ�Ϳ������������ظ����������Ϳ���ʵ���ҵ���Сֵ��ԭ��ע��һ����INT�����ֵ���������һ��
    //���Ե㲻��ͨ�������Ĭ����Сֵ������INT_MAX�����û��INT_MAX���һ�����Ե�����ˣ���
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