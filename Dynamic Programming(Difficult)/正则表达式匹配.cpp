#include<string>
#include<vector>
using namespace std;
//�����Ƕ����������Ŀ����Ҫ��״̬�Ķ���dp[i][j]����Ϊs��ǰi���ַ���p��ǰj���ַ��ܷ���ȫƥ��  ���ַ�����ȫƥ�� 
//��ʼ��״̬��Ҫ��dp[0][0]dp[0][2]dp[0][j]��ż���ĳ�ʼ�����p[j-1]=='*'��ôֱ�Ӽ̳�true
//״̬ת��:��Ҫע�⣬���� dp[0][0] ������ǿ��ַ���״̬�� ��� dp[i][j] ��Ӧ������ַ��� s[i - 1] �� p[j - 1] ��

//�� p[j - 1] = '*' ʱ�� dp[i][j] �ڵ�������һ���Ϊ truetrue ʱ���� truetrue ��
//
//dp[i][j - 2]�� �����ַ���� p[j - 2] * �������� 0 ��ʱ���ܷ�ƥ�䣻
//dp[i - 1][j] �� s[i - 1] = p[j - 2]: �����ַ� p[j - 2] ����� 1 ��ʱ���ܷ�ƥ�䣻
//dp[i - 1][j] �� p[j - 2] = '.' : �����ַ� '.' ����� 1 ��ʱ���ܷ�ƥ�䣻
//�� p[j - 1] != '*' ʱ�� dp[i][j] �ڵ�������һ���Ϊ truetrue ʱ���� truetrue ��
//
//dp[i - 1][j - 1] �� s[i - 1] = p[j - 1]�� �����ַ� p[j - 1] �����һ��ʱ���ܷ�ƥ�䣻
//dp[i - 1][j - 1] �� p[j - 1] = '.'�� �����ַ�.�����ַ� s[i - 1] ʱ���ܷ�ƥ�䣻

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1;
        int n = p.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;//�������ַ���һ��ƥ��
        //��ʼ������p�ĵ�j-1��Ϊ*��ôdp[0][j]��dp[0][j-2]����ֵά����ͬ���
        for (int j = 2;j < n;j+=2)
            dp[0][j] = dp[0][j - 2]&&p[j-1]=='*';
        for (int i = 1;i < m;i++) {
            for (int j = 1;j < n;j++) {
                if (p[j - 1] == '*') {
                    if (dp[i][j - 2])dp[i][j] = true;
                    else if (dp[i - 1][j] && s[i - 1] == p[j - 2])dp[i][j] = true;
                    else if (dp[i - 1][j] && p[j - 2] == '.')dp[i][j] = true;
                }
                else
                {
                    if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1])dp[i][j] = true;
                    else if (dp[i - 1][j - 1] && p[j - 1] == '.')dp[i][j] = true;
                }
            }
        }
        return dp[m-1][n-1];
    }
};