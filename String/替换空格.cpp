#include <string>
#include <iostream>
using namespace std;
//����ܼ򵥣�ûɶ��˵��
class Solution {
public:
    string replaceSpace(string s) {
        string temp;
        for (int i = 0;i < s.size();i++)
        {
            if (s[i] == ' ')
                temp += "%20";
            else
                temp += s[i];
        }
        return temp;
    }
};