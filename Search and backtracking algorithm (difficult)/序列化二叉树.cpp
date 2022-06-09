#include<string>
#include<queue>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 //本题利用bfs队列方法首先把二叉树结构存储成相应的字符串，然后设计一个容器vector<string>处理所有null和数字值，然后再利用bfs的逆过程
  //建立这棵树的结构，即完成了二叉树序列化的编码与解码
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)return {};
        queue<TreeNode*> q;
        string res;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if (temp)
            {
                res += to_string(temp->val) + ",";
                q.push(temp->left);
                q.push(temp->right);
            }
            else res += "null,";
        }
        return res.substr(0,res.size()-1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())return NULL;
        vector<string> v = split(data);
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(v[0]));
        q.push(root);
        int i = 1;

        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if (v[i] != "null") {
                temp->left = new TreeNode(stoi(v[i]));
                q.push(temp->left);
            }
            i++;    
            if (v[i] != "null") {
                temp->right = new TreeNode(stoi(v[i]));
                q.push(temp->right);
            }
            i++;

        }
        return root;
    }
    
    vector<string> split(string& s) {
        vector<string> v;
        int n = s.size();
        int i = 0;

        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] != ',')j++;
            v.push_back(s.substr(i, j - i));
            i = j + 1;
        }
        return v;
    }
};
    

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));