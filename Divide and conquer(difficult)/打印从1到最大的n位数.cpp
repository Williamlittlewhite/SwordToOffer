#include<vector>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> v;
        for (int i = 1;i < pow(10, n);i++)
            v.push_back(i);
        return v;
    }
};
//���⿼�Ǵ���Խ�������µĴ�ӡ������Ӧ�ÿ���ʹ���ַ������ͣ�����ʵ����������nλ��0��9��ȫ���и���
//����dfs(0,i)�ֱ�ȷ��xλ��ÿλ���֣�����int start = x == 0 ? 1 : 0; for (int i = start; i < 10; i++) 
//�����ȷ����ߵ�һλ���ֲ�Ϊ0�����඼��Ϊ0������dfs��˼����Ա���1~10**n��ȫ���У�����str��ʽ���������
#include<string>
using namespace std;
class Solution {
    vector<string> res;
    string cur;
    char NUM[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    // ���ɳ���Ϊ len �����֣�����ȷ����xλ���������ң�
    void dfs(int x, int len) {
        if (x == len) {
            res.push_back(cur);
            return;
        }
        int start = x == 0 ? 1 : 0; // X=0��ʾ��ߵ�һλ���֣�����Ϊ0
        for (int i = start; i < 10; i++) {
            cur.push_back(NUM[i]); // ȷ����λ����
            dfs(x + 1, len); // ȷ����һλ����
            cur.pop_back(); // ɾ����λ����
        }
    }
public:
    vector<string> printNumbers(int n) {
        for (int i = 1; i <= n; i++) // ���ֳ��ȣ�1~n
            dfs(0, i);
        return res;
    }
};