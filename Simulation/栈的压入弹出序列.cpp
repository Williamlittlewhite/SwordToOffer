#include <vector>
#include <stack>
using namespace std;
//栈的问题考虑辅助栈，利用模拟的思路，使得元素依次入栈当有元素和出栈序列一致那么就出栈 否则继续入栈 
//最后判断模拟的栈是否为空即可
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;

        for (int nums : pushed)
        {
            s.push(nums);
            while (!s.empty() && s.top() == popped[i])//判断条件里用i++要小心数组越界的问题最好放到循环体内
            {
                s.pop();i++;
            }
        }
        if (s.empty())return true;
        return false;
    }
};