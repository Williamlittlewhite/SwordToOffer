#include<iostream>
using namespace std;
 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 //����Ĺؼ����ڶ���������ȵ������������ϴ�����+1�����εݹ���ȥ�Ϳ�����⣡�ǳ���Ҫ  Ҳ�������ù�����Ȳ��������� ���ǵݹ���Ȼ����
class Solution {
    
public:

    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};