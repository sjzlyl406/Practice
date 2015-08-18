/*************************************************************************
	> File Name: test137.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 09时44分12秒
 ************************************************************************/

/************************************************************************
 * 如何得到一个数据流中的中位数？
 * 如果从数据流中读出奇数个数值，
 * 那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，
 * 那么中位数就是所有数值排序之后中间两个数的平均值。
 * *********************************************************************/
#include<iostream>
using namespace std;


class Solution {
public:
    void Insert(int num)
    {
        vec.push_back(num);
    }
 
    double GetMedian()
    {
        double ret(0.0F);
        sort(vec.begin(), vec.end());
        if (vec.size() & 0x01) {    //odd
            ret += (double)vec[vec.size()/2];
        }
        else {      //even
            ret += (double)vec[vec.size()/2];
            ret += (double) vec[vec.size()/2-1];
            ret /= 2.0F;
        }
        return ret;
    }
private:
    vector<int> vec;
};
