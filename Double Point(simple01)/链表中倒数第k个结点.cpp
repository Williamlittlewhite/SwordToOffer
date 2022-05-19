#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
//本题应该用快慢指针方法，首先两个指针相隔k步，然后让后指针指向最末，此时对应的前指针就是对应的倒数第k位置，具体可见代码
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