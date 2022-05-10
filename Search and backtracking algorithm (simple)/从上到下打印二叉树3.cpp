#include<vector>
#include<stack>
#include<queue>
using namespace std;
//本题利用的依然是bfs的考点，然而要注意的是学会利用deque来结合队列与栈的性质简化结果，deque在
//前端插入，即相当于栈后入先出的特性，在后端插入即是正常的队列求解方式
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        int count = 0;
        vector<vector<int>> v;
        if (!root)
            return v;
        q.push(root);
        while (!q.empty())
        {
            v.push_back(vector<int>());
            int levelsize = q.size();
            count++;
            for (int i = 0;i < levelsize;i++)
            {
                auto node = q.front();q.pop();
                if (count % 2 == 1)
                    v.back().push_back(node->val);
                else
                    s.push(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            while (!s.empty())
            {
                v.back().push_back(s.top()->val);
                s.pop();
            }
        }
        return v;
    }
};