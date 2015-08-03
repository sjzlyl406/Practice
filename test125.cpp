/*************************************************************************
	> File Name: test125.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月03日 星期一 15时06分29秒
 ************************************************************************/

/**********************************************************************
 * 已知strcpy的函数原型：char *strcpy(char *strDest, const char *strSrc)
 * strDest 是目的字符串，strSrc 是源字符串。
 * 不调用C++/C 的字符串库函数，请编写函数 strcpy。
 * *******************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>


char *Strcpy(char *strDest, const char *strStc)
{
	int len = 0;
	const char *p = strStc;
	while(*p != '\0') {
		len++;
		p++;
	}
	char *pp = strDest;
	for(int i = 0; i <= len; ++i) {
		strDest[i] = strStc[i];
	}
	return pp;
}

int main(void)
{
	char strStc[15] = "hello";
	char *str = strStc+3;

	Strcpy(str, strStc);

	printf("%s\n", str);
	return 0;
}
