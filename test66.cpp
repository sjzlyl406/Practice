/*************************************************************************
	> File Name: test66.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月08日 星期三 22时19分46秒
 ************************************************************************/

/***********************************************************
 * 任意输入两个整数，求他们的最大公约数和最小公倍数。
 * *******************************************************/
#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	while(b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
int gcd2(int a, int b)
{
	while(a != b) {
		if(a > b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	return a;
}

int lcm(int a, int b)
{
	return (a*b)/gcd(a,b);
}
int main(void)
{
	int a, b;
	cin >> a >> b;
	cout <<gcd(a,b)<<":"<<gcd2(a, b)<<":"<<lcm(a, b)<<endl;
}
