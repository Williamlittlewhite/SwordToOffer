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
 //本题重点是dfs的回溯，首先拆解dfs出来，加入路径条件是叶节点到达且target值为0则会把path路径添加 如果不为0则会path弹出最后一个位置
 //继续dfs，直到叶子节点结束会疯狂递归寻找所有路径
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