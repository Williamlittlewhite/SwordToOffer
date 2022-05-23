#include<iostream>
#include<vector>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 //本题属于中序遍历的简单题，与二叉搜索树与双链表思路一致
class Solution {
private:
    vector<TreeNode*> v;
    void dfs(TreeNode* root) {
        if (root == NULL)
            return;
        dfs(root->left);
        v.push_back(root);
        dfs(root->right);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        if (root == NULL)return -1;
        dfs(root);
        return v[v.size() - k]->val;
    }
};