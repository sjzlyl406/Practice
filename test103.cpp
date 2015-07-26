/*************************************************************************
	> File Name: test103.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月24日 星期五 10时40分18秒
 ************************************************************************/

/**********************************************************************
 * 两个数相乘的高精度算法，
 * *******************************************************************/
#include<iostream>
#include<cstdio>
#include<string>
using std::string;

string Mulitiply(string, char, int);
void Plus(string, string &);
/*********************************************
 * function:Mulitiply
 * input	:字符串1	字符串2
 * output	:字符串1 * 字符串2
 * ******************************************/
string Mulitiply(string &str1, string &str2) 
{
	size_t len1 = str1.size();
	size_t len2 = str2.size();

	if(len1 == 0 || len2 == 0) return string();
	size_t dot = 0;
	size_t dot1 = str1.find('.');
	if(dot1 < len1 ) {
		dot += len1-1-dot1;
		str1.erase(dot1, 1);
	}
	size_t dot2 = str2.find('.');
	if(dot2 < len2) {
		dot += len2 - 1 - dot2;
		str2.erase(dot2, 1);
	}

	string ret;
	for(int i = len2-1; i >= 0; --i) {
		string str_tmp = Mulitiply(str1, str2[i], len2-i-1);
		Plus(str_tmp, ret);
	}

	size_t len = ret.size();
	if(dot)
		ret.insert(len-dot, 1, '.');

	return ret;
}
/*******************************************
 * function：计算str*c的值。并在尾部添加zero_num个0
 * ****************************************/
string Mulitiply(string str, char c, int zero_num) 
{
	int carry = 0;
	string ret(str.size(), '0');
	for(int i = str.size()-1; i >= 0; --i) {
		int tmp = (str[i] - '0') * (c - '0') + carry;
		if(tmp > 9) {
			carry = tmp / 10;
			tmp = tmp % 10;
		}
		else
			carry = 0;
		ret[i] = tmp+'0';
	}
	if(carry)
		ret.insert(0, 1, carry+'0');

	ret += string(zero_num, '0');
	return ret;
}
/**********************************************
 * function:字符串加法运算，结果保存在ret中
 * *******************************************/
void Plus(string str, string &ret)
{
	int carry = 0;
	size_t len_ret = ret.size();
	size_t len_str = str.size();
	if(len_ret < len_str)
		ret.insert(0, len_str-len_ret, '0');
	size_t index = str.size()-1;
	for(int i = ret.size()-1; i >= 0; --i,--index) {
		int tmp = (str[index] - '0') + (ret[i]-'0') + carry;
		if(tmp > 9) {
			carry = 1;
			tmp = tmp % 10;
		}
		else
			carry = 0;
		ret[i] = tmp + '0';
	}
	if(carry)
		ret.insert(0,1,'1');
}


int main(void)
{
	string str1, str2;
	std::cin >> str1 >> str2;

	string str3 = Mulitiply(str1, str2);

	std::cout<<str3<<std::endl;

	return 0;
}


