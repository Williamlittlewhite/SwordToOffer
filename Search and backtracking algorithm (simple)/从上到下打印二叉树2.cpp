#include<vector>
#include<queue>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 //本题依然是层序遍历，学会二维容器的时候v.back的使用方法这有利于我们的层序遍历求解，每次队列
 //的一次遍历完成都是代表一层的遍历完成因此要通过levelsize限制层序遍历的数目，这样才更加有效
 //如果不做限制则会程序超时无法正确求解学会建立临时的二维容器方法v.push(vector<int> ())
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if (root == NULL)
            return v;
        q.push(root);
        while (!q.empty())
        {
            int levelsize = q.size();
            TreeNode* temp;
            v.push_back(vector<int>());
            for (int i = 0;i < levelsize;i++)
            {
                temp = q.front();q.pop();
                v.back().push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        return v;
    }
};