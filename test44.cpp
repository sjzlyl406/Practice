/*************************************************************************
	> File Name: test44.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月05日 星期日 20时12分29秒
 ************************************************************************/

/*********************************************************
 * 字符串匹配问题，给定两个字符串，求字符串2在字符串1中的最先匹配结果。
 * 字符串2中可以存在'*'符号，且该符号可以代表任意字符，
 * 即字符串2中存在通配符。
 * e.g. 输入：abcdefghabef, a*f    输出：abcdef''
 * *******************************************************/
#include<iostream>
#include<string>
using namespace std;

string foo(string str1, string str2)
{
	size_t p = 0;
	for(size_t left = 0; left != str1.size(); ++left) {
		if(str1[left] == str2[p] || str2[p] == '*') {
			size_t i = left;
			while(str1[i] == str2[p] || str2[p] == '*') {
				if(str1[i] == str2[p]) {
					i++; p++;
				}
				else if(str2[p] == '*') {
					if(str1[i+1] == str2[p+1]) {
						i++; p++;
					}
					else
						i++;
				}
				if(p == str2.size()) {
					string result = str1.substr(left, i);
					return result;
				}
				if(i == str1.size()) {
					string result;
					return result;
				}
			}
			p = 0;
		}
	}
	string result;
	return result;
}

int main(void)
{
	string str1, str2;
	std::cin >> str1 >> str2;

	string result = foo(str1, str2);

	std::cout << result << std::endl;
	return 0;
}

