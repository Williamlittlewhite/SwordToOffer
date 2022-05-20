#include<map>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 //本题比较简单，就是双指针的简单应用，固定一个指针，另一个指针连成链表即可
 // 两个链表头部值较小的一个节点与剩下元素的 merge 操作结果合并
  //官方题解给出一种递归的方法，递归边界是l1和l2一个为空返回另一个指针即可，否则就当l1->val<l2->val递归l1->next=merge(l1->next,l2)返回l1，
  //就当l1->val > l2->val递归l2->next=merge(l1, l2->next)返回l2即可
  //class Solution {
  //public:
  //    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  //        if (l1 == nullptr) {
  //            return l2;
  //        }
  //        else if (l2 == nullptr) {
  //            return l1;
  //        }
  //        else if (l1->val < l2->val) {
  //            l1->next = mergeTwoLists(l1->next, l2);
  //            return l1;
  //        }
  //        else {
  //            l2->next = mergeTwoLists(l1, l2->next);
  //            return l2;
  //        }
  //    }
  //};

  //作者：LeetCode - Solution
  //    链接：https ://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/solution/he-bing-liang-ge-pai-xu-de-lian-biao-by-g3z6g/
  //来源：力扣（LeetCode）
  //    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(-1);
        ListNode* re = temp;
        while (l1!=NULL&&l2!=NULL)
        {
            if (l1->val <= l2->val)
            {
                temp->next=l1;
                temp = temp->next;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        if (l1 == NULL)
            temp->next = l2;
        if (l2 == NULL)
            temp->next = l1;
        re = re->next;
        return re;
    }
};