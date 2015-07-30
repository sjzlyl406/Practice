/*************************************************************************
	> File Name: test68.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月08日 星期三 22时57分05秒
 ************************************************************************/

/*************************************************************
 * 任何一个自然数m的立方均可写成m个连续奇数之和。
 *	//　   1^3=1
	//　   2^3=3+5
	//　   3^3=7+9+11
	//　   4^3=13+15+17+19
	//编程实现：输入一自然数n，求组成n^3的n个连续奇数。
 * *******************************************************/

#include<iostream>
using namespace std;

void foo(int n)
{
	long long nnn = n * n * n;
	int left = 1, right = 1;
	long long result = left;
	while(result != nnn) {
		if(result < nnn) {
			right += 2;
			result += right;
		}
		else {
			result -= left;
			left += 2;
		}
	}
	for(int i = left ; i <= right; i = i + 2) {
		cout << i<< '\t'<<flush;
	}
}
int main(void)
{
	int i;
	cin >> i;
	foo(i);
	return 0;
}
