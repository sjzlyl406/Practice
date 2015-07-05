/*************************************************************************
	> File Name: test36.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 16时29分31秒
 ************************************************************************/

/***************************************************
 * 字符串单词首字母转换成大写
 * 举例：
 * 输入：this is a book
 * 返回：This Is A Book
 * ***************************************************/
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void ToUpper(std::string &str)
{
	size_t i = 0; 
	for(i = 0; i < str.size(); ++i) {
		if(i == 0 || isspace(str[i-1])) {
		//	str[i] += ('A' - 'a');
			str[i] = toupper(str[i]);
		}
	}
}

int main(void)
{
	std::string str;
	getline(std::cin, str);

	ToUpper(str);
	
	std::cout << str << std::endl;

	return 0;
}
