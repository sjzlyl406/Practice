/*************************************************************************
	> File Name: test159.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 10时13分44秒
 ************************************************************************/

/******************************************************************
 * 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
 * ***************************************************************/
#include<iostream>
using namespace std;


class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
         
        if (sum == 1) {
            return result;
        }
        int left = 1, right = 2, cur_sum = 3;
        while (left < right) {
            if (sum == cur_sum) {
                foo (left, right);
                right++;
                cur_sum += right;
            } else if (sum > cur_sum) {
                right++;
                cur_sum += right;
            } else {
                cur_sum -= left;
                left++;
            }
        }
        return result;
    }
     
private:
    void foo (int left, int right) {
        vector<int> path;
        for (int i = left; i <= right; ++i) {
            path.push_back(i);
        }
        result.push_back(path);
    }
     
private:
    vector<vector<int> > result;
};
