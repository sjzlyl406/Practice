/*************************************************************************
	> File Name: test98.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月22日 星期三 23时57分13秒
 ************************************************************************/

/*********************************************************************
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * *******************************************************************/
#include<cstdio>

class Solution {
	public:
		int climbStairs(int n) {
			int array[n+1] ;
			array[0] = array[1] = 1;
			for(int i = 2; i <= n; ++i) {
				array[i] = array[i-1] + array[i-2];
			}
			return array[n];
		}
};

int main(void) {
	int num = 3;
	Solution ss;
	printf("%d\n", ss.climbStairs(num));
	return 0;
}
