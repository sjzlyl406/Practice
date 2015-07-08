/*************************************************************************
	> File Name: test69.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月08日 星期三 23时11分40秒
 ************************************************************************/

/*********************************************************
 * 输入一串字符串，其中有普通的字符与括号组成（包括‘（’、‘）’、‘[’,']'）,\
 * 要求验证括号是否匹配，如果匹配则输出0、否则输出1.
 * ******************************************************/
#include<iostream>
#include<string>
using namespace std;

int foo(string str)
{
	int m = 0, n = 0;
	for(size_t i = 0; i < str.size(); ++i) {
		if(str[i] == '(')
			m++;
		if(str[i] == ')')
			if(m == 0)
				return 1;
			else
				m--;
		if(str[i] == '[')
			n++;
		if(str[i] == ']')
			if(n == 0)
				return 1;
			else
				n--;
	}
	if(m == 0 && n == 0)
		return 1;
	else
		return 1;
}
int main(void)
{
	string str;
	getline(cin, str);
	cout<<foo(str)<<endl;
	return 0;
}
