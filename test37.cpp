/*************************************************************************
	> File Name: test37.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 16时45分17秒
 ************************************************************************/

/******************************************************************
 * 通过键盘输入任意一个字符串序列，字符串可能包含多个子串，
 * 子串以空格分隔。请编写一个程序，自动分离出各个子串，
 * 并使用’,’将其分隔，并且在最后也补充一个’,’并将子串存储。  
 * 如果输入“abc def gh i        d”，结果将是abc,def,gh,i,d,。
 * **************************************************************/
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

std::string foo(std::string str)
{
	int count = 0;
	size_t i = 0;
	std::string ret;
	for(i = 0; i < str.size(); ++i) {
		if(!isspace(str[i])) {
			count = 0;
			ret += str[i];
		}
		else {
			count++;
			if(count == 1) {
				ret += ',';
			}
		}
	}
	ret += ',';
	return ret;
}
int main(void)
{
	std::string str;
	getline(std::cin, str);

	std::string ret = foo(str);

	std::cout<< ret<<std::endl;
	return 0;
}
