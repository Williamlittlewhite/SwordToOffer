#include<vector>
#include<cstdio>
using namespace std;
//�����Ƿֶ���֮���㷨˼�� ���ȸ��ݺ��������j�����һ��ȷ����  Ȼ��������������С�ڸ� �����ҵ����������һ���ڵ�m-1 
//���������ڸ� ����ҵ���������һ���ڵ�m ������p==j��֤�����������������������������Ĺ��ɣ�Ȼ��ݹ���ж�������������������
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