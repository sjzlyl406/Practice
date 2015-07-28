/*************************************************************************
	> File Name: test116.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月27日 星期一 23时14分02秒
 ************************************************************************/

/******************************************************************
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 * *****************************************************************/
#include<cmath>
#include<cstdio>

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int begin = 0;
        int end = (x+1)>>1;
        float tmp = 0;
        while(begin < end) {
            tmp = (begin + end) >> 1;
            if(fabs(tmp * tmp - x) < 0.001) return (int)tmp;
            else if(tmp * tmp < x) begin = tmp + 1;
            else end = tmp - 1;
            printf("%f\n", tmp);
        }
        tmp = end;
        if(tmp * tmp > x) return tmp-1;
        else return tmp;
    }
};


int main(void) 
{
	int a = 2147395599;
	Solution ss;
	printf("%d\n", ss.mySqrt(a));
	return 0;
}
