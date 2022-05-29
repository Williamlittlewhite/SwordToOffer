#include<iostream>
using namespace std;
//本题比较简单，逐个统计即可 但是需要注意>>也用赋值计算
class Solution {
public:
    int hammingWeight(uint32_t n) {
		int count = 0;
		while (n!=0)
		{
			if (n & 1)count++;
			n >>= 1;
		}
		return count;
    }
};
//学会n&n-1的含义就是把二进制数字n最右边的1变成0，其余不变
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n != 0)
		{
			count++;
			n &= n - 1;
		}
		return count;
	}
};