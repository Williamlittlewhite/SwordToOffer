#include <iostream>
#include <stack>
using namespace std;
//本题学会把队列换成两个栈，创建队列即创建两个栈
//入队就将某个元素入栈
//出队首先检测出栈是否为空，为空再检测入栈元素是否为空，如果为空则说明没有元素可以出队返回-1，否则
//把所有入栈元素弹出放在出栈之中，然后出列第一个元素即可；如果出栈不为空，则直接弹出第一个出栈元素即可
//这样先入的元素就可以先出，符合队列的特征，注意一般数据对象定义在private中，类内使用的函数也放在private里
class CQueue {

private:
    stack<int> instack, outputstack;
    void MoveStack() {
        while (!instack.empty())
        {
            outputstack.push(instack.top());
            instack.pop();
        }
    }


public:
    
    CQueue() {
        
    }

    void appendTail(int value) {
        instack.push(value);
    }

    int deleteHead() {
        if(outputstack.empty())
        {
            if (instack.empty())
                return -1;
            else
            {
                MoveStack();
                int temp = outputstack.top();
                outputstack.pop();
                return temp;
            }
        }
        else
        {
            int temp = outputstack.top();
            outputstack.pop();
            return temp;
        }
          
    }
};  

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */