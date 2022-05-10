#include<vector>
#include<queue>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 //������Ȼ�ǲ��������ѧ���ά������ʱ��v.back��ʹ�÷��������������ǵĲ��������⣬ÿ�ζ���
 //��һ�α�����ɶ��Ǵ���һ��ı���������Ҫͨ��levelsize���Ʋ����������Ŀ�������Ÿ�����Ч
 //�����������������ʱ�޷���ȷ���ѧ�Ὠ����ʱ�Ķ�ά��������v.push(vector<int> ())
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if (root == NULL)
            return v;
        q.push(root);
        while (!q.empty())
        {
            int levelsize = q.size();
            TreeNode* temp;
            v.push_back(vector<int>());
            for (int i = 0;i < levelsize;i++)
            {
                temp = q.front();q.pop();
                v.back().push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        return v;
    }
};