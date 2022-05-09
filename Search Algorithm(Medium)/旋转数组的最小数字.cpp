#include<vector>
using namespace std;
//����ܼ�ץס��ת������ص㼴�ɣ����ǵ��������飬�ٷ������ö��ֲ�����⣬
// ���ö��ֲ������Թ�������ؼң���������Ĳ���һ������ֲ��ң�
//class Solution {
//public:
//    int minArray(vector<int>& numbers) {
//        for (int i = 0;i < numbers.size() - 1;i++)
//            if (numbers[i] > numbers[i + 1])
//                return numbers[i + 1];
//        return numbers[0];
//    }
//};
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0;int high = numbers.size()-1;
        while (low <= high)
        {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] > numbers[high])
                low = pivot + 1;
            else if (numbers[pivot] < numbers[high])
                high = pivot;
            else
                high--;
        }
        return numbers[low];
    }
};