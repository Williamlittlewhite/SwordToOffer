#include<iostream>
using namespace std;
 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 //本题理解改递归函数：如果递归函数p，q两个都存在树中 那么返回公共结点
  //如果p存在树中,q不在树中即只存在一个在树中 那么直接返回存在的结点
  //如果都不存在直接返回null
  //当 left 和 right 同时为空 ：说明 rootroot 的左 / 右子树中都不包含 p,qp,q ，返回 nullnull ；
  //当 left 和 right 同时不为空 ：说明 p, q分列在 root 的 异侧 （分别在 左 / 右子树），因此 root 为最近公共祖先，返回 root ；
  //    当 left 为空 ，right 不为空 ：p, q都不在 root 的左子树中，直接返回 right 。具体可分为两种情况：
  //    p, q 其中一个在 root 的 右子树 中，此时 right 指向 p（假设为 p ）；
  //    p, q 两节点都在 root 的 右子树 中，此时的 right 指向 最近公共祖先节点 ；
  //    当 left 不为空 ， right 为空 ：与情况 3.同理

  //    作者：jyd
  //    链接：https ://leetcode.cn/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/mian-shi-ti-68-ii-er-cha-shu-de-zui-jin-gong-gon-7/
  //来源：力扣（LeetCode）
  //    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
  class Solution {
  public:
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          if (root == NULL || root == p || root == q) return root;
          TreeNode* left = lowestCommonAncestor(root->left, p, q);
          TreeNode* right = lowestCommonAncestor(root->right, p, q);
          if (left == NULL)return right;
          if (right == NULL)return left;
          return root;
      }
  };