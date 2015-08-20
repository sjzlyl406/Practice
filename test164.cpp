/*************************************************************************
	> File Name: test164.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月20日 星期四 15时41分49秒
 ************************************************************************/

/******************************************************************
 * 统计一个数字在排序数组中出现的次数。
 * ***************************************************************/
#include<iostream>
using namespace std;


class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int count(0);
        count = foo (data, 0, data.size(), k);
        return count;
    }
private:
    int foo (const vector<int> &data, size_t start, size_t stop, int k) {
        size_t mid = (stop - start) / 2 + start;
        if(start == stop) return 0;
         
        if (data[mid] == k) {
            int count(0), i = mid;
            while (i >= 0 && i < data.size() && data[i--] == k) count++;
            i = mid + 1;
            while (i < data.size() && data[i++] == k) count++;
            return count;
        } else if (data[mid] < k) {
            return foo (data, mid+1, stop, k);
        } else if (data[mid] > k) {
            return foo (data, start, mid, k);
        }
    }
};
