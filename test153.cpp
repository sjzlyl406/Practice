/*************************************************************************
	> File Name: test153.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 10时05分06秒
 ************************************************************************/

/******************************************************************
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 * ***************************************************************/
#include<iostream>
using namespace std;
class cc {
    public:
    cc() {
        count++;
        sum += count;
    }
    static int getsum(void) {
        return sum;
    }
    static void set(void) {
        sum = 0;
        count = 0;
    }
    private:
    static int sum;
    static int count;
};
 
int cc::sum = 0;
int cc::count = 0;
 
class Solution {
public:
    int Sum_Solution(int n) {
        cc::set();
         
        cc *tmp = new cc[n];
        int sum = cc::getsum();
        delete [] tmp;
         
        return sum;
    }
};
