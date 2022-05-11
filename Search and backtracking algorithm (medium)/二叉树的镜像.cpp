#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 //��������ķ���һ���ö��У���Ҫ��deque�����׳�ʱ���������Ž�ο��ٷ�����ǵݹ�ķ���
//class Solution {
//private:
//    queue<TreeNode*> q;
//    
//public:
//    TreeNode* mirrorTree(TreeNode* root) {
//        if (!root)
//            return NULL;
//        q.push(root);
//        while (!q.empty())
//        {
//            TreeNode* tmp=q.front();
//            if (tmp != NULL)
//            {
//                TreeNode* t = tmp->left;
//                tmp->left = tmp->right;
//                tmp->right = t;
//            }
//            q.pop();
//            if (tmp->left)q.push(tmp->left);
//            if (tmp->right)q.push(tmp->right);
//        }
//        return root;
//    }
//};
//����ʹ���˵ݹ��˼·�����������������ı�����ʽ�����Ͼ�������������������ֻ�����������ʱ�򣬼�¼���Ҷ���Ϊleft��right Ȼ�󽻻�Դ�ڵ��
//���������Ϳ����ˣ�
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        TreeNode* left = mirrorTree(root->left);
        TreeNode* right = mirrorTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};