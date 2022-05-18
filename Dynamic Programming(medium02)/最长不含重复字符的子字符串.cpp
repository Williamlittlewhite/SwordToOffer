#include<string>
#include<vector>
using namespace std;
//自己做的少考虑了前面有字符与后面构成最长字符串的情况 动态方程列错了！参照题解转换为：
// 假设dp[j]为以j右结尾的字符串的长度,i为dp[j]最大子字符串的左边第一个与之相同的索引，所以列出
// 当j-i>dp[j-1]时，dp[j]=dp[j-1]+1;当j-i<=dp[j-1]时代表dp[j]的左边界由 s[i]决定,dp[j]=j-i 
// 还有一种滑动窗口的方法是利用双指针+哈希表完成的代码注释里可见
// class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        // 哈希集合，记录每个字符是否出现过
//        unordered_set<char> occ;
//        int n = s.size();
//        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
//        int rk = -1, ans = 0;
//        // 枚举左指针的位置，初始值隐性地表示为 -1
//        for (int i = 0; i < n; ++i) {
//            if (i != 0) {
//                // 左指针向右移动一格，移除一个字符
//                occ.erase(s[i - 1]);
//            }
//            while (rk + 1 < n && !occ.count(s[rk + 1])) {
//                // 不断地移动右指针
//                occ.insert(s[rk + 1]);
//                ++rk;
//            }
//            // 第 i 到 rk 个字符是一个极长的无重复字符子串
//            ans = max(ans, rk - i + 1);
//        }
//        return ans;
//    }
//};
//
//作者：LeetCode - Solution
//链接：https ://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/solution/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-l4yo/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
            //注意这里找最左面的情况不能交换 否则会发生数组越界的情况
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