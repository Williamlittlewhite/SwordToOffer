#include<iostream>
using namespace std;
//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 //����������һ�����������������ȵĵݹ�dfs˼�룬Ȼ��������Ը��������������������������ȵ�˼�룬�����жϸýڵ��Ƿ�ƽ�⣬Ȼ��ݹ��ж���������Ȼ�󷵻�
  //�ж�ʣ�µ��������Ƿ�ƽ�⣬�����һ����ƽ��ͷ���false�����򷵻�true��
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
//����һ�����ƺ����������Ե����ϼ���߶ȵ�˼��
//���һ���ڵ������������һ����ƽ�� ��ôһ����ƽ�� ����Ϊ��־-1
//�����־Ϊ���������ϸ������ĸ߶�+1
//Ȼ���жϸ��ڵ�ĸ߶�ֻҪ����-1��Ϊƽ��
class Solution {
public:
    int height(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        if (leftheight == -1 || rightheight == -1 || abs(leftheight - rightheight) > 1)//ע�������abs
            return -1;

        return max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        
        return height(root) >= 0;
    }
};