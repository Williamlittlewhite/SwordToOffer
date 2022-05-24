#include<vector>
#include<string>
using namespace std;
//���������ַ����ıȽϽ����x+y<y+x��ô֤���ַ���x��С��y���ַ���sӦ�÷���ǰ�棬��֮��Ȼ �������ܰ������ų���С��
//������������Ĭ�������Ϊkeyֵ�����������ڱ����������Ϊkey��ôһ�������ڱ��ȶ��ҵ�С��key���������ټ����������ڱ�����key�ģ���������
//�ظ���������ֱ���ڱ���������������λ�ú�keyֵ��Ȼ��ݹ����������ߵ������鼴��
//���������ź�����ַ�����������
//ע�������ڱ�������λ�ñ������βε�l��r��ʾ��
class Solution {
private:
    void QuickSort(vector<string>& strs, int l, int r) {
        if (l >= r)return;
        int i = l;int j = r;
        while (i<j)
        {
            while (strs[j] + strs[l] >= strs[l] + strs[j]&&i<j)j--;
            while (strs[i] + strs[l] <= strs[l] + strs[i]&&i<j)i++;
            swap(strs[i], strs[j]);
        }
        swap(strs[j], strs[l]);
        QuickSort(strs, l, i - 1);
        QuickSort(strs, i + 1, r);
    }
public:
    string minNumber(vector<int>& nums) {
        vector<string> strings;
        string res;
        for (int i = 0;i < nums.size();i++)
            strings.push_back(to_string(nums[i]));
        QuickSort(strings, 0, strings.size() - 1);
        for (auto    s : strings)
            res.append(s);
        return res;
    }
};