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
    //һ�α������뷨����,���ö��������������ʣ���ͬ����һ������һ�����ڵ��ڸýڵ�ֵ��һ��С�� 
    //���� һ��С�ڵ��ڸù�ͬ���Ƚڵ�ֵ��һ�������
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