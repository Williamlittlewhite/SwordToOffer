//1.学会利用&&符合来代替日常的递归出口if(n==0) return 0;这一情况
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n-1));
        return n;
    }
};
//2.学会利用加法与位运算代替乘法，，，有点复杂没必要
// 考虑 A 和 B 两数相乘的时候我们如何利用加法和位运算来模拟，其实就是将 B 二进制展开，
//如果 B 的二进制表示下第 ii 位为 1，那么这一位对最后结果的贡献就是 A*(1<<i)A∗(1<<i) ，
//即 A<<iA<<i。我们遍历 B 二进制展开下的每一位，将所有贡献累加起来就是最后的答案
// int quickMulti(int A, int B) {
//int ans = 0;
//for (; B; B >>= 1) {
//    if (B & 1) {
//        ans += A;
//    }
//    A <<= 1;
//}
//return ans;
//}
//
//作者：LeetCode - Solution
//链接：https ://leetcode.cn/problems/qiu-12n-lcof/solution/qiu-12n-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//class Solution {
//public:
//    int sumNums(int n) {
//        int ans = 0, A = n, B = n + 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        (B & 1) && (ans += A);
//        A <<= 1;
//        B >>= 1;
//
//        return ans >> 1;
//    }
//};
//
//作者：LeetCode - Solution
//链接：https ://leetcode.cn/problems/qiu-12n-lcof/solution/qiu-12n-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。