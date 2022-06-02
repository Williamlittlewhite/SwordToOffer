#include<vector>
#include<unordered_map>
using namespace std;
//��ϣ��ļ��뷨��ע���ڴ洢��Ѱ�ҵĹ����й�ϣ�����һ��ѭ��������ʱ 
//�ڶ��������ǽ���������ȡ�м���һ��������
//��ţ�Ƶķ�����ͶƱ�󷨣���������Ʊ��Ϊ+1,��������Ʊ��Ϊ-1,��һ�����������ֵ�Ʊ����>0���ǵ�ǰ��һ����Ϊ�����������Ϊ0ʱ�������������
//��һ����������,Ȼ����еݹ鼴��
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