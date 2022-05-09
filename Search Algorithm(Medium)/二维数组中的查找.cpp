#include<vector>
using namespace std;
//本题最简单的方法采用遍历就可以，但是时空复杂度过高，参看答案,将矩阵逆时针旋转45度，可以看做一个搜索树的问题
// 可以把左下或者右上当做根，如果比根大则舍去这一列，比根小则舍去这一行，然后重复上述过程，最后找到目标值，
// 如果没找到的返回未找到！
//class Solution {
//public:
//    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//        for (int i = 0;i < matrix.size();i++)
//        {
//            for (int j = 0;j < matrix[i].size();j++)
//            {
//                if (matrix[i][j] == target)
//                    return true;
//            }
//        }
//        return false;
//    }
//
//};

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1, j = 0;
        while (i>=0&&j<matrix[0].size())
        {
            int flag = matrix[i][j];
            if (target < flag)
                i--;
            else if (target > flag)
                j++;
            else
                return true;
        }
        return false;
    }

};