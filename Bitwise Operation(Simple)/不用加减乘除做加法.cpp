//本题的求和可以转化为非进位求和（即各位异或与各位的进位求和进行递归直至为0）  因为b是求与最终会归0 而异或不容易得0 所以终止条件b=0
//要注意b要转换成无位符号数 因为有的编译器不支持负数的左移
class Solution {
public:
    int add(int a, int b) {
        if (b == 0)
            return a;
        return add(a^b, (unsigned int)(a & b) << 1);
    }
};
//C++详细非递归版本 不如递归好理解
class Solution {
public:
    int add(int a, int b) {
        //因为不允许用+号，所以求出异或部分和进位部分依然不能用+ 号，所以只能循环到没有进位为止        
        while (b != 0)
        {
            //保存进位值，下次循环用
            int c = (unsigned int)(a & b) << 1;//C++中负数不支持左移位，因为结果是不定的
//保存不进位值，下次循环用，
            a ^= b;
            //如果还有进位，再循环，如果没有，则直接输出没有进位部分即可。
            b = c;
        }
        return a;
    }
};