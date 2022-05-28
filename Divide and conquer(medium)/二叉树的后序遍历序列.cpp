#include<vector>
#include<cstdio>
using namespace std;
//本题是分而治之的算法思想 首先根据后序遍历的j就最后一个确定根  然后由于左子树都小于根 所以找到左子树最后一个节点m-1 
//右子树大于根 因此找到右子树第一个节点m 如果最后p==j则证明该子树满足二叉搜索树后序遍历的规律，然后递归的判断左子树和右子树即可
class Solution {
private:
    bool recur(int i, int j,vector<int> postorder)
    {
        if (i >= j)return true;
        int p = i;
        while (postorder[p] < postorder[j])p++;
        int m = p;
        while (postorder[p] > postorder[j])p++;
        return p == j && recur(i, m - 1,postorder) && recur(m, j - 1,postorder);
        
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(0, postorder.size() - 1,postorder);
    }
};