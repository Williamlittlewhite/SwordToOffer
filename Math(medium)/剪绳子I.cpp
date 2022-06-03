//本题是数学推导，首先根据算术几何不等式推出均分的时候相等，然后利用求导推出驻点得到均分为3的时候是最大值，此时如果剩余长度为2的情况
//保留 因为2>1*1 如果剩余为1 则拿出一个3 变成2*2>1*3
#include<math.h>
using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        int a = 0, b = 0;
        if (n <= 3)
            return n - 1;
        else
        {
            a = n / 3;
            b = n % 3;
        }
        if (b == 0)
            return pow(3, a);
        if (b == 1)
            return pow(3, a - 1) * 2 * 2;
        return pow(3, a) * b;
    }
};