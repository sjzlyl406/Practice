/*************************************************************************
	> File Name: test13.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月01日 星期三 09时22分51秒
 ************************************************************************/

/*****************************************************************
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、
 * case等关键字及条件判断语句（A？B：C）。
 * **************************************************************/
#include<iostream>
#include<stack>

using namespace std;

/********** first ***********/
class Temp
{
	public:
		Temp() { n++; sum += n; }

		static void reset() { n = 0; sum = 0;}
		static unsigned int getNum() { return sum; }
	private:
		static int n;
		static int sum;
};
int Temp::n = 0;
int Temp::sum = 0;
/*********** second ************/
class A;
A* Array[2];

class A
{
	public:
		virtual unsigned int Sum (unsigned int n){
			return 0;
		}
};
class B : public A
{
	public:
		virtual unsigned int Sum (unsigned int n){
			return Array[!!n]->Sum(n-1) + n;
		}
};
int Sum_solution2(int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;

	int value = Array[1]->Sum(n);
	
	return value;
}

/************ third ***********/
typedef unsigned int (*func)(unsigned int n);
unsigned int Sum_terminal(unsigned int n)
{
	return 0;
}
unsigned int Sum3(unsigned int n)
{
	static func array[] = {Sum_terminal, Sum3};
	return array[!!n](n-1) + n;
}




int main(void)
{
	int n = 10;
	Temp::reset();
	
	Temp *tt = new Temp[n];

	int ans = Temp::getNum();
	delete [] tt;
	tt = NULL;

	std::cout << ans << std::endl;

	return 0;
}
