/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//反转链表，利用空头结点然后依次创建链表来完成，遍历原链表的过程中，创建新的链表节点，使得新链表的节点
//转换为前驱节点，即原链表第一个节点next连在新的空节点上，第二个节点next连在原链表的第一个节点上依次类推即可反转链表
#include<iostream>
#include<algorithm>//内含null
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