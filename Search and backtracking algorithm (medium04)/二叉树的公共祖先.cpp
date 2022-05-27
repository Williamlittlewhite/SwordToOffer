#include<iostream>
using namespace std;
 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 //�������ĵݹ麯��������ݹ麯��p��q�������������� ��ô���ع������
  //���p��������,q�������м�ֻ����һ�������� ��ôֱ�ӷ��ش��ڵĽ��
  //�����������ֱ�ӷ���null
  //�� left �� right ͬʱΪ�� ��˵�� rootroot ���� / �������ж������� p,qp,q ������ nullnull ��
  //�� left �� right ͬʱ��Ϊ�� ��˵�� p, q������ root �� ��� ���ֱ��� �� / ������������� root Ϊ����������ȣ����� root ��
  //    �� left Ϊ�� ��right ��Ϊ�� ��p, q������ root ���������У�ֱ�ӷ��� right ������ɷ�Ϊ���������
  //    p, q ����һ���� root �� ������ �У���ʱ right ָ�� p������Ϊ p ����
  //    p, q ���ڵ㶼�� root �� ������ �У���ʱ�� right ָ�� ����������Ƚڵ� ��
  //    �� left ��Ϊ�� �� right Ϊ�� ������� 3.ͬ��

  //    ���ߣ�jyd
  //    ���ӣ�https ://leetcode.cn/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/mian-shi-ti-68-ii-er-cha-shu-de-zui-jin-gong-gon-7/
  //��Դ�����ۣ�LeetCode��
  //    ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
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