/*************************************************************************
	> File Name: test61.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月06日 星期一 12时26分44秒
 ************************************************************************/

/*******************************************************************
 * 输入一个只包含个位数字的简单四则运算表达式字符串，计算该表达式的值
 * 注： 1、表达式只含 +, -, *, /, (, ), 四则运算符
 * 2、表达式数值只包含个位整数(0-9)，且不会出现0作为除数的情况
 * 3、要考虑加减乘除按通常四则运算规定的计算优先级
 * 4、除法用整数除法，即仅保留除法运算结果的整数部分。比如8/3=2。输入表达式保证无0作为除数情况发生
 * 5、输入字符串一定是符合题意合法的表达式，其中只包括数字字符和四则运算符字符，除此之外不含其它任何字符，不会出现计算溢出情况
 * ***************************************************************/
#include<iostream>
#include<stack>
#include<string>
#include<cctype>
#include<algorithm>

int RPExpression(std::string str) 
{
	std::stack<char> s1,	//临时存放运算符
		s2;					//存放逆波兰表达式

	std::string::iterator iter = str.begin();
	while(iter != str.end()) {
		switch(*iter) {
			case '(' : {
				s1.push('(');
				break;
			}
			case ')' : {
				char c = s1.top();
				while(c != '(') {
					s2.push(c);
					s1.pop();
					c = s1.top();
				}
				s1.pop();
				break;
			} 
			case '*' : {
				while(!s1.empty() &&s1.top() == '/') {
					char c = s1.top();
					s2.push(c);
					s2.pop();
				}
				s1.push('*');
				break;
			}
			case '/' : {
				while(!s1.empty() && s1.top() == '*') {
					char c = s1.top();
					s2.push(c);
					s2.pop();
				}
				s1.push('/');
				break;
			}
			case '+' :  {
				if(!s1.empty() && s1.top() != '(') {
					while(!s1.empty() && (
								s1.top() == '*' || 
								s1.top() == '/' || 
								s1.top() == '-')) {
						char c = s1.top();
						s2.push(c);
						s1.pop();
					}
				}
				s1.push(*iter);
				break;					
			}
			case '-' : {
				if(!s1.empty() &&s1.top() != '(') {
					while(!s1.empty() && (
								s1.top() == '*' || 
								s1.top() == '/' || 
								s1.top() == '+')) {
						char c = s1.top();
						s2.push(c);
						s1.pop();
					}
				}
				s1.push(*iter);
				break;
			}
			default : {
				s2.push(*iter);
				break;
			}
		}
		++iter;
	}
	while(!s1.empty()) {
		char c = s1.top();
		s2.push(c);
		s1.pop();
	}

	while(!s2.empty()) {
		char c = s2.top();
		s1.push(c);
		s2.pop();
	}
	while(!s1.empty()) {
		char c = s1.top();
		if(isdigit(c)) {
			s2.push(c);
		}
		else {
			char c2 = s2.top();
			s2.pop();
			char c1 = s2.top();
			s2.pop();
			switch (c){
				case '+': {
					c = c1 + c2 - '0';
					break;
				}
				case '-' : {
					c = c1 - c2 + '0';
					break;
				}
				case '*' : {
					c = ((c1-'0') * (c2-'0')) + '0';
					break;
				}
				case '/' : {
					c = ((c1-'0') / (c2-'0')) + '0';
					break;
				}
			}
			s2.push(c);
		}
		s1.pop();		
	}
	char c = s2.top();
	return (c-'0');
}

int main(void)
{
	std::string str;
	std::cin >> str;

	std::cout <<str << " = " << \
		RPExpression(str) <<std::endl;
	return 0;
}

