#include<vector>
using namespace std;
//������򵥵ķ������ñ����Ϳ��ԣ�����ʱ�ո��Ӷȹ��ߣ��ο���,��������ʱ����ת45�ȣ����Կ���һ��������������
// ���԰����»������ϵ�����������ȸ�������ȥ��һ�У��ȸ�С����ȥ��һ�У�Ȼ���ظ��������̣�����ҵ�Ŀ��ֵ��
// ���û�ҵ��ķ���δ�ҵ���
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