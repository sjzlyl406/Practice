/*************************************************************************
	> File Name: test92.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月21日 星期二 23时05分18秒
 ************************************************************************/

/***********************************************************************
 * Implement pow(x, n).
 * *********************************************************************/
#include<iostream>
class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) {
            return 1.0 / myPow1(x, -n);
        }
        else
            return myPow1(x, n);
    }
private:
    double myPow1(double x, int n) {
        if(n == 0) return 1.0;
        if(n == 1) return x;
        
        double v = myPow1(x, n/2);
        if(n & 0x01 == 1)
            return x * v * v;
        else
            return v * v;
    }
};
