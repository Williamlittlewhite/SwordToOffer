#include<vector>
using namespace std;
//��������ѧ�ķ�����Լɪ�򻷷��ֵĹ��ɼ�f(n)=(f(n-1)+t)%n=(f(n-1)+m%n)%n=(f(n-1)+m)%n ���԰�ɾ��������Ϊһ����̬�滮������
//f(n)Ϊ��ģΪn��������µĽ�  f(1)=0Ϊ0��ʼ���� �ӹ�ģΪ1��̬�滮����ģΪn����
class Solution {
public:
    int lastRemaining(int n, int m) {
        int x = 0;
        for (int i = 2;i <= n;i++) {
            x = (x + m) % i;
        }
        return x;
   
    }
};