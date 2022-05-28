#include<vector> 
#include<unordered_map>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 //这个重建二叉树实际上就是分而治之的想法，已知前序和中序 首先前序提取根(root)中序找到根的索引，然后确定了中序的左右子树的索引
  //即left,i-1,i+1,right；进一步确定左子树的前序根索引和右子树的前序根索引即可对于左子树root+1而对于右子树其根为root+i-left+1
  //其中i-left表示左子树的长度还要+1才是右子树前序的根。
class Solution {
private:
    vector<int> preorder;
    unordered_map<int, int> m;
    TreeNode* recur(int root, int left, int right) {
        if (left > right)return NULL;
        TreeNode* node = new TreeNode(preorder[root]);
        int i = m[preorder[root]];
        node->left = recur(root+1, left, i - 1);
        node->right = recur(root+i-left+1, i + 1, right);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for (int i = 0;i < inorder.size();i++)
            m[inorder[i]] = i;
        return recur(0, 0, inorder.size() - 1);
    }

};