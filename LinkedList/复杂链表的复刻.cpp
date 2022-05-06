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
//������û����㷨+��ϣ��map����˼�룬��¼ԭ��ÿ���ڵ�Ϊkey valueΪdeepcopy���±��Ӧ�ڵ㣬ͨ�����ַ�ʽ�ж�
//�Ƿ�ԭ��ĸýڵ㱻�����㷨�����������ⲻ��Ҫ���ظ���Ȼ�����õݹ�˼�룬����һֱ��ԭ����һ���ڵ���и��ƣ�����
//ԭ�����һ���ڵ��ʱ���˻أ���ԭ�����󵽵�һ��������ڵ������Ӧrandom���Ĵ���
//���㷨�Ļ���˼���ǣ���һ��·��ǰ�ߣ��ܽ���������ܽ����˻�������һ��·���ԣ��Ӷ��������ִ��ض��յ��
//һ�����߶����ض�·��
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