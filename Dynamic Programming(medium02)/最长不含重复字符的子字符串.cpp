#include<string>
#include<vector>
using namespace std;
//�Լ������ٿ�����ǰ�����ַ�����湹����ַ�������� ��̬�����д��ˣ��������ת��Ϊ��
// ����dp[j]Ϊ��j�ҽ�β���ַ����ĳ���,iΪdp[j]������ַ�������ߵ�һ����֮��ͬ�������������г�
// ��j-i>dp[j-1]ʱ��dp[j]=dp[j-1]+1;��j-i<=dp[j-1]ʱ����dp[j]����߽��� s[i]����,dp[j]=j-i 
// ����һ�ֻ������ڵķ���������˫ָ��+��ϣ����ɵĴ���ע����ɼ�
// class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        // ��ϣ���ϣ���¼ÿ���ַ��Ƿ���ֹ�
//        unordered_set<char> occ;
//        int n = s.size();
//        // ��ָ�룬��ʼֵΪ -1���൱���������ַ�������߽����࣬��û�п�ʼ�ƶ�
//        int rk = -1, ans = 0;
//        // ö����ָ���λ�ã���ʼֵ���Եر�ʾΪ -1
//        for (int i = 0; i < n; ++i) {
//            if (i != 0) {
//                // ��ָ�������ƶ�һ���Ƴ�һ���ַ�
//                occ.erase(s[i - 1]);
//            }
//            while (rk + 1 < n && !occ.count(s[rk + 1])) {
//                // ���ϵ��ƶ���ָ��
//                occ.insert(s[rk + 1]);
//                ++rk;
//            }
//            // �� i �� rk ���ַ���һ�����������ظ��ַ��Ӵ�
//            ans = max(ans, rk - i + 1);
//        }
//        return ans;
//    }
//};
//
//���ߣ�LeetCode - Solution
//���ӣ�https ://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/solution/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-l4yo/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        if (s == "")
//            return 0;
//        vector<int> dp(50000);
//        int max = 1;
//        dp[0] = 0;
//        dp[1] = 1;
//        string temp = "";
//        temp += s[0];
//        for (int i = 2;i <= s.size();i++)
//        {
//            if (temp.find(s[i - 1], 0) == temp.npos)
//            {
//                temp += s[i - 1];
//                dp[i] = dp[i - 1] + 1;
//                if (dp[i] > max)
//                    max = dp[i];
//            }
//            else
//            {
//                dp[i] = 1;
//                temp = s[i - 1];
//            }
//
//        }
//        return max;
//    }
//
//};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size == 0)
            return 0;
        else if (size == 1)
            return 1;
        vector<int> dp(size+1,0);
        dp[0] = 1;
        int max = 0;
        for (int j = 1;j < size;j++)
        {
            int i = j - 1;
            //ע���������������������ܽ��� ����ᷢ������Խ������
            while (i >= 0 && s[i] != s[j])i--;
            if (dp[j - 1] < j - i)
            {
                dp[j] = dp[j - 1] + 1;
                if (dp[j] > max)
                    max = dp[j];
            }
            else if (dp[j - 1] >= j - i)
            {
                dp[j] = j - i;
                if (dp[j] > max)
                    max = dp[j];
            }
        }
        return max;
    }
};