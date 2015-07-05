/*************************************************************************
	> File Name: test34.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 15时25分05秒
 ************************************************************************/

/***************************************************************
 * 将输入的字符串（字符串仅包含小写字母‘a’到‘z’），按照如下规则，
 * 
 * 循环转换后输出：a->b,b->c,…,y->z,z->a；
 * 若输入的字符串连续出现两个字母相同时，后一个字母需要连续转换2次。
 * 
 * 例如：aa 转换为 bc，zz 转换为 ab；
 * 当连续相同字母超过两个时，第三个出现的字母按第一次出现算。
 * **************************************************************/
#include<iostream>
#include<string>

void Change(std::string &str)
{
	size_t i = 0;
	for(i = 0; i < str.size(); ++i) {
		if(str[i] == 'z')
			str[i] = 'a';
		else
			str[i]++;
	}

	bool flag = true;
	for(i = 1; i < str.size(); ++i) {
		if(flag = true && str[i] == str[i-1]) {
			if(str[i] == 'z')
				str[i] = 'a';
			else
				str[i]++;
			flag = false;
		}
		else
			flag = true;
	}
}
int main(void)
{
	std::string str;
	std::cin >> str;

	Change(str);

	std::cout << str << std::endl;

	return 0;
}

