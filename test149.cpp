/*************************************************************************
	> File Name: test149.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 10时03分34秒
 ************************************************************************/

/******************************************************************
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法
 * ***************************************************************/
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        if ( len == 0) return A;
         
        vector<int> vec1(len, 1), vec2(len, 1);
         
        //记录A中前0 ～ i-1个乘积
        for (int i = 1; i < len; ++i) {
            vec1[i] = vec1[i-1] * A[i-1];
        }
        //记录A中后i+1 ～ n-1个乘积
        for (int i = len-2; i >= 0; --i) {
            vec2[i] = vec2[i+1] * A[i+1];
        }
        //组合成数组B
        for (int i = 0; i < len; ++i) {
            vec1[i] = vec1[i] * vec2[i];
        }
        return vec1;
    }
};
