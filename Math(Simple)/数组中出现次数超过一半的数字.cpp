#include<vector>
#include<unordered_map>
using namespace std;
//哈希表的简单想法，注意在存储与寻找的过程中哈希表放在一个循环，否则超时 
//第二个方法是将数组排序取中间数一定是众数
//最牛逼的方法是投票大法，记众数的票数为+1,非众数的票数为-1,则一定有所有数字的票数和>0，记当前第一个数为众数，当求和为0时候则把新子数组
//第一个当做众数,然后进行递归即可
class Solution {
private:
    unordered_map<int, int> m;
public:
    int majorityElement(vector<int>& nums) {
        int temp = 0;
        int cnt = nums.size() / 2;
        for (int i : nums)
        {
            m[i] += 1;
            if (m[i] > cnt)
                temp = i;
        }
        return temp;
    }
};


class Solution {
private:
    int vote = 0, x = 0;
public:
    int majorityElement(vector<int>& nums) {
        for (int i : nums)
        {
            if (vote == 0)
                x = i;
            vote += (x == i) ? 1 : -1;
        }
        return x;
    }
};