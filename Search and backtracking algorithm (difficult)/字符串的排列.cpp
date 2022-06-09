#include<vector>
#include<set>
#include<string>
using namespace std;
//参考题解，利用递归分别确定从0到最后size-1的位置的所有字母，利用set记录某个固定位置是否是相同的字符，如果是相同字符则不用交换，否则
//不断交换，最终可以实现所有字符串的排列。
class Solution {
public:
    vector<string> v;
    
    vector<string> permutation(string s) {
        dfs(s, 0);
        return v;
    }
    void dfs(string& s, int x) {
        set<int> st;
        if (x == s.size() - 1)
        {
            v.push_back(s);
            return;
        }
        for (int i = x;i < s.size();i++)
        {
            if (st.find(s[i])!= st.end())continue;
            st.insert(s[i]);
            swap(s[i], s[x]);
            dfs(s, x + 1);
            swap(s[i], s[x]);
        }
    }
};