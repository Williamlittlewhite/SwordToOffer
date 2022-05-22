#include<vector>
#include<string>
#include<queue>
using namespace std;
//������ѣ��漰���˾���ݹ飬��������˫ѭ���õ�dfs�����г�ʼ״̬��Ȼ����dfs
//���ݾ���Ĵ�С�����ַ����Ĺ�ϵ������߽�����������ַ������������Ƿ�ﵽĿ�궨���Ƿ��ҵ�����
//ע�����õݹ�ǰboard�ĸ�ֵ���ⲻ��Ҫ�ĵݹ� ���û����㷨 ע�����õݹ��board�ĸ�ֵ��ԭԭ���鷽����һ����ʼ�������
class Solution {
private:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k)
    {
        int row = board.size();
        int col = board[0].size();
        if (i < 0 || i >= row || j < 0 || j >= col||board[i][j]!=word[k]) return false;
        if (k == word.size() - 1) return true;
        board[i][j] = '\0';
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = word[k];
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        int k = 0;
        for (int i = 0;i < row;i++) {
            for (int j = 0;j < col;j++) {
                if(dfs(board, word, i, j, k)) return true;
            }
        }
        return false;
    }
};