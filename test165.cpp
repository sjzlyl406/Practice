/*************************************************************************
	> File Name: test165.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月20日 星期四 15时42分39秒
 ************************************************************************/

/******************************************************************
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，
 * 则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
 * ***************************************************************/
#include<iostream>
using namespace std;


class Solution {
public:
    int InversePairs(vector<int> data) {
        int count(0);
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = i+1; j < data.size(); ++j) {
                if (data[i] > data[j])
                    count++;
            }
        }
        return count;
    }
};
