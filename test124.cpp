/*************************************************************************
	> File Name: test124.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月03日 星期一 10时52分14秒
 ************************************************************************/

/***************************************************************
 * Strlen()的c语言实现，不能使用任何变量
 * *************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>

int Strlen(char *str)
{
	if(*str == '\0') return 0;
	return Strlen(str+1) + 1;
}

int main(void)
{

	char str[] = "hello";
	int len1 = strlen(str);
	int len2 = Strlen(str);

	printf("%d %d\n", len1, len2);

	return 0;
}
