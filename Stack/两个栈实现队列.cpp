#include <iostream>
#include <stack>
using namespace std;
//����ѧ��Ѷ��л�������ջ���������м���������ջ
//��Ӿͽ�ĳ��Ԫ����ջ
//�������ȼ���ջ�Ƿ�Ϊ�գ�Ϊ���ټ����ջԪ���Ƿ�Ϊ�գ����Ϊ����˵��û��Ԫ�ؿ��Գ��ӷ���-1������
//��������ջԪ�ص������ڳ�ջ֮�У�Ȼ����е�һ��Ԫ�ؼ��ɣ������ջ��Ϊ�գ���ֱ�ӵ�����һ����ջԪ�ؼ���
//���������Ԫ�ؾͿ����ȳ������϶��е�������ע��һ�����ݶ�������private�У�����ʹ�õĺ���Ҳ����private��
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