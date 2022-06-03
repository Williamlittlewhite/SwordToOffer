#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
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