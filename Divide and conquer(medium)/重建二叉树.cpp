#include<vector> 
#include<unordered_map>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 //����ؽ�������ʵ���Ͼ��Ƿֶ���֮���뷨����֪ǰ������� ����ǰ����ȡ��(root)�����ҵ�����������Ȼ��ȷ�����������������������
  //��left,i-1,i+1,right����һ��ȷ����������ǰ�����������������ǰ����������ɶ���������root+1���������������Ϊroot+i-left+1
  //����i-left��ʾ�������ĳ��Ȼ�Ҫ+1����������ǰ��ĸ���
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