/*************************************************************************
	> File Name: test60.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月06日 星期一 11时17分28秒
 ************************************************************************/

/*******************************************************************
 * 通过键盘输入100以内正整数的加、减运算式，请编写一个程序输出运算结果字符串。
 * 输入字符串的格式为：“操作数1 运算符 操作数2”，“操作数”与“运算符”之间以一个空格隔开。
 * ***************************************************************/
#include<stdio.h>
#include<ctype.h>
#include<string>
#include<iostream>

int ctonum(char* str)
{
	int result = 0;
	char *p = str;
	while(*p != '\0') {
		result = result * 10 + (*p - '0');
		p++;
	}
	return result;
}

int calcul(char* str) 
{
	char *p = str;
	int oper = 1;
	while(*p != '\0') {
		if(*p == '+')
			oper = 1;
		if(*p == '-')
			oper = 0;
		p++;
	}

	p = str;
	char num1[100] = {0};
	char num2[100] = {0};
	
	int i = 0, j = 0;
	while(!isdigit(*p)) p++;
	while(isdigit(*p)) {
		num1[i++] = *p;
		p++;
	}
	while(!isdigit(*p)) p++;
	while(isdigit(*p)) {
		num2[j++] = *p;
		p++;
	}

	if(oper == 1) {
		return ctonum(num1)+ctonum(num2);
	}
	else
		return ctonum(num1)-ctonum(num2);

}

int main(void)
{
	char str[100] = {0};
	std::cin.getline(str,100);

	int result = calcul(str);

	printf("%d\n", result);
	return 0;
}


