//本题注意0的时候默认也为1种跳法，然后类似斐波那契数列利用动态规划即可以求解啦(动态数组)即跳上n层台阶等于跳上n-1级和n-2级数目的求和
//因为最后的话只能跳1级台阶或者两级台阶即从n-1级跳和n-2级跳即可！
class Solution {
public:
    int numWays(int n) {
        int MOD = 1000000007;
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        int p = 0, q = 1, r = 1;
        for (int i = 2; i <= n;i++)
        {
            p = q;
            q = r;
            r = (p + q) % MOD;
        }
        return r;
    }
};