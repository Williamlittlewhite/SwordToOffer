//自己的想法超出时间限制，即不能用递归的方法，学习动态规划的方法
class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        return (fib(n - 1) + fib(n - 2))%10000000007;
    }
};
//动态规划即需要一个递归公式，利用滚动数组的想法即可
class Solution {
public:
    int fib(int n) {
        int MOD = 1000000007;
        int p=0, q=0, r=1;
        if (n<2)
            return n;
        for (int i = 2;i <= n;i++)
        {
            p = q;
            q = r;
            r = (p + q) % MOD;
        }
        return r;
    }
};