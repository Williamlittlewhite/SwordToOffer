#include<string>
#include<vector>
#include<algorithm>
//本题双指针思想，利用continue找到尾部第一个j,再利用while找到第一个空格位置，进一步可以加入字符串中
//利用j=i，循环迭代上述过程即可翻转整个字符串！
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string res;
        for (int j = s.size() - 1;j >= 0;j--)
        {
            if (s[j] == ' ')continue;
            int i = j;
            while (i >= 0 && s[i] != ' ')i--;       //双指针一定要先判断指针本身&&再加其他条件 否则容易越界
            res.append(s.substr(i + 1, j - i));  //注意substr第二参数是长度,利用j-(i+1)+1求得
            res.append(" ");
            j = i;
        }
        if (!res.empty()) res.pop_back();
        return res;
    }
};