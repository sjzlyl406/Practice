/*************************************************************************
	> File Name: test63.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月08日 星期三 20时38分40秒
 ************************************************************************/

/*****************************************************************
 * 求一个正整数X的平方根Y，立方根Z。
 * 求平方根和立方根我们一般用牛顿迭代法，下面是对应的公式。
 * 平方根迭代公式a(n+1)=(a(n)+Y/a(n))/2，其中Y为待求平方根。
 * 立方根迭代公式a(n+1)={2a(n)+Z/{[a(n)]^2}}/3，其中Z为待求平方根。
 * ****************************************************************/
#include<iostream>
#include<cmath>
using namespace std;

/************* first :y = x^2 ***************/
double Sqrt(double x, double y) 
{
	if(fabs(x) < 0.000001)
		return 0.0;
	while(fabs(x*x-y) > 0.000001) {
		x = x - (x*x - y)/(2*x);
	}
	return x;
}

/*************** second : y = x^3 ****************/
double Cube(double x, double y)
{
	if(fabs(2*x*x) < 0.000001)
		return 0.0;
	while(fabs(x*x*x - y) > 0.0000001) {
		x = x - (x*x*x-y)/(2*x*x);
	}
	return x;
}
/*********** third : y = 2*x^3+4*x^2+x *************/
double NewTon(double x, double y) 
{
	if(fabs(6*x*x+8*x+1) < 0.00000001)
		return 0.0;
	while(fabs(2*x*x*x+4*x*x+x-y) > 0.0000001) {
		x = x - (2*x*x*x+4*x*x+x-y)/(6*x*x+8*x+1);
	}
	return 0;
}
int main(void)
{
	double x = 0.0;
	cin >> x;
	x = Sqrt(1, x);
	cout << x;
	return 0;
}
