#include<iostream>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
//����������������������ǰ�˳��Ĵ�С�����һ�����У����ⶨ����ָ��head��pre��headָ�����·���Ҷ�ڵ㣬pre����cur��ǰһ���ڵ�
//��pre��Ϊ�յ�ʱ������Ҫ����pre��cur��˫��ָ�� ����ֻ��Ҫ��¼ͷ���λ��Ȼ�����������ﴦ��ͷβ�ڵ�Ϳ��ԣ�Ȼ��ݹ���pre=cur���¼���
//��������ĳ������ͣ�
class Solution {
private://���Զ����ָ��Ĭ��ָ��NULL
    Node* head;
    Node* pre;
    void dfs(Node* cur) {
        if (cur == NULL)return;
        dfs(cur->left);
        if (pre == NULL)
        {
            head = cur;
        }
        else
        {   
            cur->left = pre;
            pre->right = cur;
        }
        pre = cur;
        dfs(cur->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL)return NULL;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};