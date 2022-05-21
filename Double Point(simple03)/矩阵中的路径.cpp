#include<vector>
#include<string>
#include<queue>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        queue<char> q;
        int i = 0,j=-1,k=-1;
        q.push(board[++j][++k]);
        while (!q.empty())
        {
            if (q.front() != word[i++])
                continue;
            q.pop();
            while (j<board.size()&&k<board[0].size())
            {
                q.push(board[++j][k]);
                q.push(board[--j][++k]);
            }
            
        }
        if(i==word.size()-1)
            return false;
        return true;
    }
};