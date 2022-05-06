    /*
    // Definition for a Node.
    class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
    };
    */
#include<algorithm>
#include<unordered_map>
using namespace std;
//本题采用回溯算法+哈希表（map）的思想，记录原表每个节点为key value为deepcopy的新表对应节点，通过这种方式判断
//是否原表的该节点被回溯算法所遍历过避免不必要的重复，然后利用递归思想，首先一直对原表下一个节点进行复制，当到
//原表最后一个节点的时候退回，对原表从最后到第一个的随机节点进行相应random结点的创建
//溯算法的基本思想是：从一条路往前走，能进则进，不能进则退回来，换一条路再试，从而搜索到抵达特定终点的
//一条或者多条特定路径
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
private:
    unordered_map<Node*, Node*> m;
public:
    
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        while (!m.count(head))
        {
            Node* node = new Node(head->val);
            m[head] = node;
            node->next=copyRandomList(head->next);
            node->random=copyRandomList(head->random);
        }
        return m[head];
    }
};