/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include<algorithm>
//本题很简单，就是链表的一个普通的遍历过程！
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
private:
    vector<int> v;
public:
    vector<int> reversePrint(ListNode* head) {
        while (head!=NULL)
        {
            v.push_back(head->val);
            head = head->next;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};