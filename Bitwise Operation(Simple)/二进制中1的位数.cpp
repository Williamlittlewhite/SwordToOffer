#include<iostream>
using namespace std;
//����Ƚϼ򵥣����ͳ�Ƽ��� ������Ҫע��>>Ҳ�ø�ֵ����
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
//ѧ��n&n-1�ĺ�����ǰѶ���������n���ұߵ�1���0�����಻��
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