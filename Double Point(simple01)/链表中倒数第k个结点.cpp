#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
//����Ӧ���ÿ���ָ�뷽������������ָ�����k����Ȼ���ú�ָ��ָ����ĩ����ʱ��Ӧ��ǰָ����Ƕ�Ӧ�ĵ�����kλ�ã�����ɼ�����
//class Solution {
//public:
//    ListNode* getKthFromEnd(ListNode* head, int k) {
//        int length = 0,temp=0;
//        ListNode* t1=head;
//        if (head == NULL)
//            return NULL;
//        while (head!=NULL)
//        {
//            length++;
//            head = head->next;
//        }
//        length = length - k + 1;
//        while (temp != length-1&&t1!=NULL)
//        {
//            temp++;
//            t1 = t1->next;
//        }
//        return t1;
//    }
//};
  class Solution {
  public:
      ListNode* getKthFromEnd(ListNode* head, int k) {
          ListNode* fast = head;
          ListNode* slow = head;
          while (k--)
          {
              fast = fast->next;
          }
          while (fast != NULL)
          {
              fast = fast->next;
              slow = slow->next;
          }
          return slow;
      }
  };