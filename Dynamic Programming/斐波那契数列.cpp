//�Լ����뷨����ʱ�����ƣ��������õݹ�ķ�����ѧϰ��̬�滮�ķ���
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
//��̬�滮����Ҫһ���ݹ鹫ʽ�����ù���������뷨����
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