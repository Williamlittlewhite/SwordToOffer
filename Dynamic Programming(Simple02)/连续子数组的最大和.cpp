#include<vector>
#include<algorithm>
using namespace std;
//����Ƚϼ򵥣�������������⣬���ǵ�����������Ļ�����ô���ֵһ���Ǵ�0��ʼ�ӵ� û�������Ļ�ֱ��������ֵ���� ��ʵ���Ƕ���˼��
//����Ե�i-1������β������������dp[i-1]>0��ôdp[i]�Ϳ��ǽ�dp[i-1]+nums[i]��Ϊ�����п���ʹ�ú����͸������dp[i-1]С��0 ��ô
// ֱ�Ӱ�nums[i]��Ϊdp[i]���Ե�i����β���������ͼ��ɣ����ұ������ֱ����ԭ���������ʡ�ռ�
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0, max = *max_element(nums.begin(),nums.end());
        if (max < 0)
            return max;
        for (int i = 0;i < nums.size();i++)
        {
            sum += nums[i];
            if (sum < 0)
                sum = 0;
            if (sum > max)
                max = sum;
        }
        return max;
    }
};