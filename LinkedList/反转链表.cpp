/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//��ת�������ÿ�ͷ���Ȼ�����δ�����������ɣ�����ԭ����Ĺ����У������µ�����ڵ㣬ʹ��������Ľڵ�
//ת��Ϊǰ���ڵ㣬��ԭ�����һ���ڵ�next�����µĿսڵ��ϣ��ڶ����ڵ�next����ԭ����ĵ�һ���ڵ����������Ƽ��ɷ�ת����
#include<iostream>
#include<algorithm>//�ں�null
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node;
        ListNode* newnode=NULL;
        while (head!=NULL)
        {
            node = new ListNode(head->val);
            node->next = newnode;
            newnode = node;
            head = head->next;
        }
        return node;
    }
};