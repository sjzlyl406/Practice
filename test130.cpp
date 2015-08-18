/*************************************************************************
	> File Name: test130.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月12日 星期三 08时03分36秒
 ************************************************************************/

/*******************************************************************
 * 在实际项目中，我们可能会用字符串来表示无法用普通数据类型（int/float）来存储的数值，在这里我们把它们定义为大数。请实现两个字符串表示的大数相减的程序。例如：“1234567890123.1”-“123456789.1”=“1234444433334” 
 * 要求： 
 * 1、可以使用任何语言。 
 * 2、不可以使用大数类。 
 * 输出的结果也是用字符串表示的大数
 * ***************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>

std::string foo(std::string str1, std::string str2);

int main(void) {
	std::string str1, str2;
	std::cout << "input two numbers:";
	std::cin >> str1 >> str2;

	std::cout<<str1 << " - " << str2 << " = " <<
		foo(str1, str2) << std::endl;

	return 0;
}

std::string foo(std::string str1, std::string str2) {
	size_t dot1_index = str1.find('.');
	size_t dot2_index = str2.find('.');
	//没有'.'的补上'.'
	if(dot1_index == str1.npos) {
		str1 += '.';
		dot1_index = str1.find('.');
	}
	if(dot2_index == str2.npos) {
		str2 += '.';
		dot2_index = str2.find('.');
	}
	size_t length1 = str1.size();
	size_t length2 = str2.size();
	//小数点后补0
	if((length1 - dot1_index) != (length2 - dot2_index)) {
		int tmp = length1 - dot1_index - length2 + dot2_index;
		if(tmp < 0) {
			str1.append(fabs(tmp), '0');
		}
		else {
			str2.append(fabs(tmp), '0');
		}
	}
	//比较大小 + 定义minus位
	bool minus = false;	//负数位
	if(str1.size() < str2.size()) {
		str1.insert(0, str2.size()-str1.size(), '0');
	}
	else if(str1.size() > str2.size()) {
		str2.insert(0, str1.size()-str2.size(), '0');
	}
	for(size_t i = 0; i < str1.size(); ++i) {
		if(str1[i] != str2[i]) {
			if(str1[i] < str2[i]) {
				swap(str1, str2);
				minus = true;
			}
			break;
		}
	}
	//定义借位标志carry
	bool carry = false;
	std::string ret;
	for(int i = str1.size()-1; i >= 0; --i) {
		if(str1[i] != '.') {
			int sum_tmp = 0;
			if(carry)  {
				str1[i]--;
				carry = false;
			}
			if(str1[i] < str2[i]) {
				carry = true;
			}
			sum_tmp = str1[i] - str2[i];
			if(carry) sum_tmp += 10;
			ret += (sum_tmp + '0');
		}
		else {
			ret += '.';
		}
	}
	if(carry) ret += '1';

	//去掉开头的0 和 小数点后全为0时不显示小数位
	size_t i = 0;
	while(ret[i] == '0') {
		i++;
	}
	if(ret[i] == '.') i++;
	ret.erase(0, i);
	reverse(ret.begin(), ret.end());
	i = 0;
	while(i < ret.size() && ret[i] == '0') {
		i++;
	}
	if(ret[i] == '.') i--;
	ret.erase(0, i);
	if(minus) {
		ret.insert(0, "-");
	}
	return ret;
}
