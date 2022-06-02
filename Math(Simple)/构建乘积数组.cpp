#include<vector>
using namespace std;
//该方法超时，参考题解，题解的用的是N*N矩阵转换为求下三角乘积 再乘上上三角乘积即可
/*如下所示先计算下三角 然后对应计算上三角 乘积即可
 1   1 2 3 4 5  120 = 1*a[4]*a[3]*a[2]*a[1]
 1   1 1 3 4 5   60 = 1*a[4]*a[3]*a[2]
 2   1 2 1 4 5   40 = 2*a[4]*a[3]
 6   1 2 3 1 5   30 = 6*a[4]从这里开始第二重循环
 24  1 2 3 4 1   24 
*/
//class Solution {
//public:
//    vector<int> constructArr(vector<int>& a) {
//        vector<int> v;
//
//        for (int i = 0;i < a.size();i++)
//        {
//            int temp = i;
//            int sum = 1;
//            for (int j = 0;j < a.size();j++)
//            {
//                if (j == temp)continue;
//                sum *= a[j];
//            }
//            v.push_back(sum);
//        }
//        return v;
//    }
//};
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        if (len == 0)
            return {};//返回这个函数所构造出来的对象,返回类型与函数类型一样
        vector<int> b(len, 1);
        for (int i = 1;i < len;i++)
            b[i] = b[i - 1] * a[i - 1];
        int tmp = 1;
        for (int j =len-2 ;j >= 0;j--)
        {
            tmp *= a[j + 1];
            b[j] *= tmp;
        }
        return b;
    }
};