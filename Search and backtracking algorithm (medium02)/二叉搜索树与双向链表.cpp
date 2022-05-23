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
//二叉搜索树的中序遍历就是按顺序的从小到大的一个排列，本题定义类指针head和pre，head指向左下方的叶节点，pre代表cur的前一个节点
//当pre不为空的时候则需要建立pre和cur的双向指针 否则只需要记录头结点位置然后在主函数里处理头尾节点就可以，然后递归令pre=cur往下即可
//中序遍历的常见题型！
class Solution {
private://属性定义的指针默认指向NULL
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