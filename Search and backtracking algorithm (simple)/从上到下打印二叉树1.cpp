#include<vector>
#include<queue>
using namespace std;
//����Ƚϼ򵥣�����һ������������ѣ���ס����bfs�ķ�������ǳ������ף�ģ�廯���
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
private:
    queue<TreeNode*> q;
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> v;
        if (root == NULL)
            return v;
        q.push(root);
        while (!q.empty())
        {
            v.push_back(q.front()->val);
            if((q.front())->left!=NULL)
                q.push(q.front()->left);
            if ((q.front())->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
        return v;
    }
};