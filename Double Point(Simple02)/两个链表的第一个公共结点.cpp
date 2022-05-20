#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 //本题我用的是双指针遍历思想，注意结点相交是指地址相等而不是值！参看题解的方法优化  其一为利用unordered_map哈希表储存每个指针，然后判断每个
  //指针是否存在即可
  //双指针的想法:两个跑速一样的人在不同长短的跑道里跑，怎么才能让他们遇见，不断交换他们的跑道 参见解法3 非常机智！
  class Solution {
  public:
      bool cmp(ListNode* l1, ListNode* l2)
      {
          while (l1 != NULL && l2 != NULL)
          {
              if (l1 != l2)
                  return false;
              l1 = l1->next;
              l2 = l2->next;
          }
          return true;
      }
      ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
          ListNode* temp1 = headA;
          ListNode* temp2 = headB;
          while (temp1 != NULL)
          {
              while (temp2 != NULL)
              {
                  ListNode* result = temp1;
                  if (cmp(temp1, temp2))
                      return result;
                  temp2 = temp2->next;
              }
              temp1 = temp1->next;
              temp2 = headB;
          }
          return NULL;
      }
  };
  //    class Solution {
//    public:
//        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//            unordered_set<ListNode*> visited;
//            ListNode* temp = headA;
//            while (temp != nullptr) {
//                visited.insert(temp);
//                temp = temp->next;
//            }
//            temp = headB;
//            while (temp != nullptr) {
//                if (visited.count(temp)) {
//                    return temp;
//                }
//                temp = temp->next;
//            }
//            return nullptr;
//        }
//    };
//
//    作者：LeetCode - Solution
//        链接：https ://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/liang-ge-lian-biao-de-di-yi-ge-gong-gong-pzbs/
//    来源：力扣（LeetCode）
//        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//};
    //class Solution {
    //public:
    //    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    //        if (headA == nullptr || headB == nullptr) {
    //            return nullptr;
    //        }
    //        ListNode* pA = headA, * pB = headB;
    //        while (pA != pB) {
    //            pA = pA == nullptr ? headB : pA->next;
    //            pB = pB == nullptr ? headA : pB->next;
    //        }
    //        return pA;
    //    }
    //};