#include<vector>
#include<string>
#include<queue>
using namespace std;
//本题较难，涉及到了矩阵递归，首先利用双循环得到dfs的所有初始状态，然后定义dfs
//根据矩阵的大小和与字符串的关系定义其边界情况，根据字符串计数符号是否达到目标定义是否找到单词
//注意利用递归前board的赋值避免不必要的递归 利用回溯算法 注意利用递归后board的赋值还原原数组方便下一个初始点遍历！
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