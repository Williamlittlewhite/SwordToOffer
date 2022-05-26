#include<iostream>
using namespace std;
 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 //本题的关键在于二叉树的深度等于左右子树较大的深度+1，依次递归下去就可以求解！非常重要  也可以利用广度优先层序遍历求解 但是递归显然更简单
class Solution {
    
public:

    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};