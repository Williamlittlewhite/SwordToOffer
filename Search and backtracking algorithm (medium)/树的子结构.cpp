#include<iostream>
//����Ƚ��� �õ��ǵݹ�˼���ж��ӽṹ���⣬����дһ�������жϴ������ڵ㿪ʼ�����Ƿ�����ͬ�����BΪ��
//����ͬ��AΪ�ջ���ֵ��һ����ʾ��ͬ������ýڵ���ͬ��ݹ�ĵ�����ڵ��Լ��ҽڵ㿴�Ƿ���ͬ��ע������
//�ĵݹ����룬��Ϊ�������ҽڵ㶼��ͬ����֤�����ӽṹ
//�ڶ����������õ�һ�������������ж�A/B�Ƿ���һ��Ϊ�գ���һ��Ϊ����ֱ��������������ж���A/B
//Ϊ�����Ƿ����ӽṹ��������򷵻�true ����͵ݹ鿴A���������ĸ����������ĸ��Ƿ���BΪ�ӽṹ
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