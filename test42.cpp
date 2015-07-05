/*************************************************************************
	> File Name: test42.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 18时40分43秒
 ************************************************************************/

/**********************************************************
 * 给定两个非常大的正整数A和B，位数在50到100之间。求C=A+B；
 * 如输入：111111111111111111111111111111111111111
 *		   222222222222222222222222222222222222222
 * 输出：333333333333333333333333333333333333333
 * ******************************************************/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

std::string Plus(std::string str1, std::string str2)
{
	size_t p = 0;
	std::string ret;
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	char carry = 0;

	if(str1.size() < str2.size())
		swap(str1, str2);

	size_t i = 0;
	for(i = 0; i < str2.size(); ++i) {
		char c = str1[i] + str2[i] + carry - '0';
		if(c > '9') {
			carry = 1;
			c = (c-'0') % 10 + '0';
		}
		else
			carry = 0;
		ret += c;
	}
	while(i < str1.size()) {
		char c = str1[i++] + carry;
		if(c > '9')  {
			carry = 1;
			c = '0';
		}
		else
			carry = 0;
		ret += c;
	}
	if(carry == 1)
		ret += '1';
	reverse(ret.begin(), ret.end());

	return ret;
}

int main(void)
{
	std::string str1, str2;
	std::cin >> str1 >> str2 ;

	std::string ret = Plus(str1, str2);

	std::cout << ret <<std::endl;

	return 0;
}
