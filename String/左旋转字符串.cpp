#include<string>
#include<iostream>
using namespace std;
//�����ܼ򵥣�Ҳ��ѧ���ַ�������������
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