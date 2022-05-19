#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 //本题是一个删除链表节点的想法，(我们可以学会创造一个空节点的方法来简化判断第一个节点的情况），题解给出的双指针是利用两个指针记录
 // 一前一后两个指针，找到要删除的值，使得前指针的next赋值为后指针的next即可 需要注意的是第一个节点的特殊情况
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

  //作者：jyd
  //    链接：https ://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/solution/mian-shi-ti-18-shan-chu-lian-biao-de-jie-dian-sh-2/
  //来源：力扣（LeetCode）
  //    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
        while (temp != NULL && temp->next != NULL) //temp!=NULL&&temp->next!=NULL用到temp->next判断一定要先去判断temp不为空否则报错
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