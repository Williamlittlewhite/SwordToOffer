#include<string>
#include<unordered_map>
using namespace std;
//本题考察哈希表也就是map的使用方法！学会使用unordered_map类似字典那样实现查找！
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