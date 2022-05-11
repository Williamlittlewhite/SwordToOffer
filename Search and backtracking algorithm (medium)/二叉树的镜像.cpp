#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 //层序遍历的方法一定用队列，不要用deque很容易超时，本题最优解参考官方解答是递归的方法
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
//本题使用了递归的思路及方法，类似于树的遍历方式，不断镜像树的左右子树，当只有三个顶点的时候，记录左右顶点为left和right 然后交换源节点的
//左右子树就可以了！
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