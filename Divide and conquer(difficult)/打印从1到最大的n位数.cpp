#include<vector>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> v;
        for (int i = 1;i < pow(10, n);i++)
            v.push_back(i);
        return v;
    }
};
//本题考虑大数越界的情况下的打印，大数应该考虑使用字符串类型，本题实际上求解的是n位数0—9的全排列个数
//利用dfs(0,i)分别确定x位数每位数字，利用int start = x == 0 ? 1 : 0; for (int i = start; i < 10; i++) 
//的语句确定左边第一位数字不为0，其余都可为0，利用dfs的思想可以遍历1~10**n的全排列，利用str格式处理大数！
#include<string>
using namespace std;
class Solution {
    vector<string> res;
    string cur;
    char NUM[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    // 生成长度为 len 的数字，正在确定第x位（从左往右）
    void dfs(int x, int len) {
        if (x == len) {
            res.push_back(cur);
            return;
        }
        int start = x == 0 ? 1 : 0; // X=0表示左边第一位数字，不能为0
        for (int i = start; i < 10; i++) {
            cur.push_back(NUM[i]); // 确定本位数字
            dfs(x + 1, len); // 确定下一位数字
            cur.pop_back(); // 删除本位数字
        }
    }
public:
    vector<string> printNumbers(int n) {
        for (int i = 1; i <= n; i++) // 数字长度：1~n
            dfs(0, i);
        return res;
    }
};