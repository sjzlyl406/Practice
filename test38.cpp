/*************************************************************************
	> File Name: test38.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 16时56分24秒
 ************************************************************************/

/********************************************************************
 * 输入一个字符串，删除其中所有的数字，
 * 所有大写字母改成小写，其他不变，并输出。
 * ****************************************************************/
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

std::string foo(std::string str)
{
	size_t i = 0;
	std::string ret;
	for(i = 0; i < str.size(); ++i) {
		if(!isdigit(str[i])) {
			ret += tolower(str[i]);
		}
	}
	return ret;
}

int main(void)
{
	std::string str;
	getline(std::cin, str);
	std::string ret = foo(str);

	std::cout<<ret<<std::endl;

	return 0;
}
