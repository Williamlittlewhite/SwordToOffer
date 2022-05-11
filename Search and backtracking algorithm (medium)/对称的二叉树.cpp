#include<iostream>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 //二叉树问题一般都转换为递归，本题的思路是判断镜像转换为判断二叉树的左右子树是否为镜像的，即检查左子树的左子树和右子树的右子树是否相等
 //左子树的右子树和右子树的左子树是否相等，终止条件即其左右孩子不对称或者值不一样的情况！
class Solution {
public:
    bool Judge(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;
        if (!left || !right|| left->val!=right->val)
            return false;
        return Judge(left->left, right->right) && Judge(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return  true;
       
        return Judge(root->left,root->right);
    }
};