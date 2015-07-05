/*************************************************************************
	> File Name: test39.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 17时01分58秒
 ************************************************************************/

/********************************************************************
 * 编写一个字符串替换函数，如：“ABCDEFGHIJKLMNOPQRSTUVWXYZ”这个字符串，
 * 把其中的“RST”替换为“ggg”这个字符串，
 * 结果就变成了：ABCDEFGHIJKLMNOPQgggUVWXYZ
 * *****************************************************************/
#include<iostream>
#include<string>

std::string replace(std::string str1, std::string str2, std::string str3)
{
	std::string result;
	size_t len = str2.size();

	size_t left = 0;
	size_t right = str1.find(str2);
	while(right != str1.npos) {
		result += str1.substr(left, right - left);
		result += str3;
		left = right + len;
		right = str1.substr(left).find(str2);
	}
	result += str1.substr(left);
	return result;
}
int main(void)
{
	std::string str1;
	getline(std::cin, str1);

	std::string str2;
	getline(std::cin, str2);
	
	std::string str3;
	getline(std::cin, str3);

	std::string result;
	result = replace(str1, str2, str3);

	std::cout << result << std::endl;

	return 0;
}
