#include<string>
#include<unordered_map>
using namespace std;
//���⿼���ϣ��Ҳ����map��ʹ�÷�����ѧ��ʹ��unordered_map�����ֵ�����ʵ�ֲ��ң�
class Solution {
private:
    unordered_map<char, int> m;
public:
    char firstUniqChar(string s) {
        for (int i = 0;i < s.size();i++) {
            m[s[i]]++;
       }
        for (int j = 0;j < s.size();j++) {
            if (m[s[j]] == 1)
                return s[j];
        }
        return ' ';

            
    }
};