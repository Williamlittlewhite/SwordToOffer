#include<map>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 //����Ƚϼ򵥣�����˫ָ��ļ�Ӧ�ã��̶�һ��ָ�룬��һ��ָ������������
 // ��������ͷ��ֵ��С��һ���ڵ���ʣ��Ԫ�ص� merge ��������ϲ�
  //�ٷ�������һ�ֵݹ�ķ������ݹ�߽���l1��l2һ��Ϊ�շ�����һ��ָ�뼴�ɣ�����͵�l1->val<l2->val�ݹ�l1->next=merge(l1->next,l2)����l1��
  //�͵�l1->val > l2->val�ݹ�l2->next=merge(l1, l2->next)����l2����
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

  //���ߣ�LeetCode - Solution
  //    ���ӣ�https ://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/solution/he-bing-liang-ge-pai-xu-de-lian-biao-by-g3z6g/
  //��Դ�����ۣ�LeetCode��
  //    ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
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