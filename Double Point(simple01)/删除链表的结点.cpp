#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 //������һ��ɾ������ڵ���뷨��(���ǿ���ѧ�ᴴ��һ���սڵ�ķ��������жϵ�һ���ڵ�����������������˫ָ������������ָ���¼
 // һǰһ������ָ�룬�ҵ�Ҫɾ����ֵ��ʹ��ǰָ���next��ֵΪ��ָ���next���� ��Ҫע����ǵ�һ���ڵ���������
  //class Solution {
  //public:
  //    ListNode* deleteNode(ListNode* head, int val) {
  //        if (head->val == val) return head->next;
  //        ListNode* pre = head, * cur = head->next;
  //        while (cur != nullptr && cur->val != val) {
  //            pre = cur;
  //            cur = cur->next;
  //        }
  //        if (cur != nullptr) pre->next = cur->next;
  //        return head;
  //    }
  //};

  //���ߣ�jyd
  //    ���ӣ�https ://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/solution/mian-shi-ti-18-shan-chu-lian-biao-de-jie-dian-sh-2/
  //��Դ�����ۣ�LeetCode��
  //    ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* t1 = NULL;
        if (head->val == val)
        {
            head = head->next;return head;
        }
        if (head == NULL)
            return head;
        while (temp != NULL && temp->next != NULL) //temp!=NULL&&temp->next!=NULL�õ�temp->next�ж�һ��Ҫ��ȥ�ж�temp��Ϊ�շ��򱨴�
        {
            
            if (temp->next->val == val)
            {
                temp->next = temp->next->next;
            }
            t1 = temp;
            temp = temp->next;
        }
        if (temp != NULL && temp->next != NULL)
        {
            if (temp->val == val)
                t1->next = NULL;
        }
        return head;
    }
};