#include <vector>
using namespace std;
//��̬�滮���뷨��������̨�׺�쳲��������еı��֣�����dp[i]Ϊ�Ӹ�λ���i��������ӵ�еķ����������ڱ��⶯�滮
//�����ǶԳƵ����Ǵ���������б�������ʹ������ҷ�����ɶ���һ���ģ��������������֣����Ǵ���������
// ��һ���е�����������ɵ�ֵ��10~25֮��dp[1]=1,dp[2]=2�����
//���ǿ������dp[0]=1 ����쳲��������й��� 
//���ö��滮dp[i]=dp[i-1]+dp[i-2]�Լ�dp[i]=dp[i-1]������⼴��
class Solution {
public:
    int translateNum(int num) {
        vector<int> dp(10000);
        dp[0]=1;
        dp[1]=1;
        int i = 2;
        int temp1 = num % 10;
        while (num!=0)
        {
            num /= 10;
            int temp2 = num % 10;
            if (temp1 + 10*temp2 <= 25 && temp1 +10*temp2 >= 10)
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
            temp1 = temp2;
            i += 1;
        }
        return dp[i - 1];
    }
};