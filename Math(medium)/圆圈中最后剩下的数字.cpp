#include<vector>
using namespace std;
//本题用数学的方法即约瑟夫环发现的规律即f(n)=(f(n-1)+t)%n=(f(n-1)+m%n)%n=(f(n-1)+m)%n 可以把删除数组作为一个动态规划问题解决
//f(n)为规模为n的最后留下的解  f(1)=0为0初始条件 从规模为1动态规划到规模为n即可
class Solution {
public:
    int lastRemaining(int n, int m) {
        int x = 0;
        for (int i = 2;i <= n;i++) {
            x = (x + m) % i;
        }
        return x;
   
    }
};