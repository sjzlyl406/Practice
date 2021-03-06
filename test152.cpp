/*************************************************************************
	> File Name: test152.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 10时04分47秒
 ************************************************************************/

/******************************************************************
 * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 * ***************************************************************/
#include<iostream>
using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        int or_, and_;
        while (num2) {
            or_ = num1 ^ num2;
            and_ = (num1 & num2) << 1;
            num1 = or_;
            num2 = and_;
        }
        return num1;
    }
};
