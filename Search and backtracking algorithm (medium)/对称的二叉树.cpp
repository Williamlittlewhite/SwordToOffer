#include<iostream>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 //����������һ�㶼ת��Ϊ�ݹ飬�����˼·���жϾ���ת��Ϊ�ж϶����������������Ƿ�Ϊ����ģ�������������������������������������Ƿ����
 //�������������������������������Ƿ���ȣ���ֹ�����������Һ��Ӳ��Գƻ���ֵ��һ���������
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