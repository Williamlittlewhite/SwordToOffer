#include<string>
#include<vector>
#include<algorithm>
//����˫ָ��˼�룬����continue�ҵ�β����һ��j,������while�ҵ���һ���ո�λ�ã���һ�����Լ����ַ�����
//����j=i��ѭ�������������̼��ɷ�ת�����ַ�����
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string res;
        for (int j = s.size() - 1;j >= 0;j--)
        {
            if (s[j] == ' ')continue;
            int i = j;
            while (i >= 0 && s[i] != ' ')i--;       //˫ָ��һ��Ҫ���ж�ָ�뱾��&&�ټ��������� ��������Խ��
            res.append(s.substr(i + 1, j - i));  //ע��substr�ڶ������ǳ���,����j-(i+1)+1���
            res.append(" ");
            j = i;
        }
        if (!res.empty()) res.pop_back();
        return res;
    }
};