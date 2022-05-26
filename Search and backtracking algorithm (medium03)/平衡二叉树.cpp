#include<iostream>
using namespace std;
//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 //首先利用上一题计算二叉树的最大深度的递归dfs思想，然后根据再自根向下类似先序遍历那样计算深度的思想，首先判断该节点是否平衡，然后递归判断左子树，然后返回
  //判断剩下的右子树是否平衡，如果有一个不平衡就返回false，否则返回true。
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        else
            return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
//还有一中类似后续遍历，自底向上计算高度的思想
//如果一个节点的左右子树有一个不平衡 那么一定不平衡 设置为标志-1
//否则标志为左右子树较高子树的高度+1
//然后判断根节点的高度只要不是-1即为平衡
class Solution {
public:
    int height(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        if (leftheight == -1 || rightheight == -1 || abs(leftheight - rightheight) > 1)//注意这里的abs
            return -1;

        return max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        
        return height(root) >= 0;
    }
};