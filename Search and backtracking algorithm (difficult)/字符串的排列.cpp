#include<vector>
#include<set>
#include<string>
using namespace std;
//�ο���⣬���õݹ�ֱ�ȷ����0�����size-1��λ�õ�������ĸ������set��¼ĳ���̶�λ���Ƿ�����ͬ���ַ����������ͬ�ַ����ý���������
//���Ͻ��������տ���ʵ�������ַ��������С�
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