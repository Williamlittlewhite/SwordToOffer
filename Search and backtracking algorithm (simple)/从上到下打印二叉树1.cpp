#include<vector>
#include<queue>
using namespace std;
//本题比较简单，就是一个层序遍历而已，记住利用bfs的方法处理非常的容易，模板化编程
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
private:
    queue<TreeNode*> q;
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> v;
        if (root == NULL)
            return v;
        q.push(root);
        while (!q.empty())
        {
            v.push_back(q.front()->val);
            if((q.front())->left!=NULL)
                q.push(q.front()->left);
            if ((q.front())->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
        return v;
    }
};