#include<iostream>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    //一次遍历的想法即可,利用二叉搜索树的性质，共同祖先一定满足一个大于等于该节点值另一个小于 
    //或者 一个小于等于该共同祖先节点值另一个则大于
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        while (true) {
            if (p->val < temp->val && q->val < temp->val)
                temp = temp->left;
            else if (p->val > temp->val && q->val > temp->val)
                temp = temp->right;
            else
                break;
        }
        return temp;

    }
};