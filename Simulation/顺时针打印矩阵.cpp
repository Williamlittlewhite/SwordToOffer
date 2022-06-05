#include<vector>
using namespace std;
/*
简单模拟矩阵的实际打印情况，首先设定上下界，利用从左到右规律，从上到下规律，从右到左，从下到上时候不断缩小边界，直到某个边界条件满足
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        vector<int> v;
        while (true)
        {
            for (int i = l;i <= r;i++)
                v.push_back(matrix[t][i]);
            if (++t > b)break;
            for (int i = t;i <= b;i++)
                v.push_back(matrix[i][r]);
            if (l > --r)break;
            for (int i = r;i >= l;i--)
                v.push_back(matrix[b][i]);
            if (t>--b)break;
            for (int i = b;i >= t;i--)
                v.push_back(matrix[i][l]);
            if (++l>r)break;
        }
        return v;
    }
};