#include<unordered_map>
#include<string>
using namespace std;
//本题考虑有限状态机，通过状态机状态转换表设置状态为开始、结束、符号、数值；数值和符号对求和有影响，其他则过度，最后将两个记录变量
//相互乘积即可求解
class Solution {
public:
    string state = "start";
    unordered_map <string, vector<string>> table = {
          {"start",{"start","signed","in_number","end"}},
          {"signed",{"end","end","in_number","end"}},
          {"in_number",{"end","end","in_number","end"}},
          {"end",{"end","end","end","end"}}
    };
    int getcol(char c) {
        if (isspace(c))return 0;
        if (c == '+' || c == '-')return 1;
        if (isdigit(c))return 2;
        return 3;
    }
    int sign = 1;
    long long ans = 0;
    void get(char c) {
        state = table[state][getcol(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if(state=="signed")
        {
            sign = c == '+' ? 1 : -1;
        }
    }
    int strToInt(string str) {
        for (char c : str) {
            get(c);
        }
        return sign * ans;
        
    }
};