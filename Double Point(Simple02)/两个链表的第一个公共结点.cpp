#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 //�������õ���˫ָ�����˼�룬ע�����ཻ��ָ��ַ��ȶ�����ֵ���ο����ķ����Ż�  ��һΪ����unordered_map��ϣ����ÿ��ָ�룬Ȼ���ж�ÿ��
  //ָ���Ƿ���ڼ���
  //˫ָ����뷨:��������һ�������ڲ�ͬ���̵��ܵ����ܣ���ô�������������������Ͻ������ǵ��ܵ� �μ��ⷨ3 �ǳ����ǣ�
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
//    ���ߣ�LeetCode - Solution
//        ���ӣ�https ://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/liang-ge-lian-biao-de-di-yi-ge-gong-gong-pzbs/
//    ��Դ�����ۣ�LeetCode��
//        ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
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