#include<iostream>
//本题比较难 用的是递归思想判断子结构问题，首先写一个函数判断从两个节点开始的树是否是相同，如果B为空
//则相同，A为空或者值不一样表示不同，如果该节点相同则递归的调用左节点以及右节点看是否相同，注意这里
//的递归是与，因为必须左右节点都相同才能证明是子结构
//第二个函数利用第一个函数，首先判断A/B是否有一个为空，有一个为空则直接跳过；否则就判断以A/B
//为根的是否是子结构，如果是则返回true 否则就递归看A的左子树的根和右子树的根是否与B为子结构
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool recur(TreeNode* A, TreeNode* B)
    {
        if (B == NULL)
            return true;
        else if (A == NULL || A->val != B->val)
            return false;
        else
            return recur(A->left, B->left) && recur(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL)
            return false;
        else
            return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};