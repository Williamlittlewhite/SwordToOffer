#include <vector>
#include <stack>
using namespace std;
//ջ�����⿼�Ǹ���ջ������ģ���˼·��ʹ��Ԫ��������ջ����Ԫ�غͳ�ջ����һ����ô�ͳ�ջ ���������ջ 
//����ж�ģ���ջ�Ƿ�Ϊ�ռ���
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;

        for (int nums : pushed)
        {
            s.push(nums);
            while (!s.empty() && s.top() == popped[i])//�ж���������i++ҪС������Խ���������÷ŵ�ѭ������
            {
                s.pop();i++;
            }
        }
        if (s.empty())return true;
        return false;
    }
};