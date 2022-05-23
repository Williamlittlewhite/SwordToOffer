#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 //�����ص���dfs�Ļ��ݣ����Ȳ��dfs����������·��������Ҷ�ڵ㵽����targetֵΪ0����path·����� �����Ϊ0���path�������һ��λ��
 //����dfs��ֱ��Ҷ�ӽڵ��������ݹ�Ѱ������·��
class Solution {
private:
    vector<vector<int>> v;
    vector<int> path;
    void dfs(TreeNode* root, int target) {
        if (root == NULL)return;
        target -= root->val;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL && target == 0)v.emplace_back(path);
        dfs(root->left, target);
        dfs(root->right, target);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return v;
    }
};