#include<string>
#include<iostream>
using namespace std;
//这个题很简单，也是学会字符串遍历就行了
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string temp;
        for (int i = n;i < s.size();i++)
        {
                temp += s[i];
        }
        for (int i = 0;i < n ;i++)
        {
            temp += s[i];
        }
        return temp;
    }
};