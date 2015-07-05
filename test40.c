/*************************************************************************
	> File Name: test40.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 17时17分21秒
 ************************************************************************/

/****************************************************************
 * 将两个字符串合并为一个字符串并且输出，用指针实现。
 * *************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *catchar(char* str1, char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int len = len1 + len2 + 1;
	char *result = (char*)malloc(len * sizeof(char));
	memset(result, 0, len*sizeof(char));

	char *p = result;
	while(*str1 != '\0')
		*p++ = *str1++;
	while(*str2 != '\0')
		*p++ = *str2++;

	return result;
}

int main(void)
{
	char str1[20] = {0}, str2[20] = {0};
	scanf("%s %s",str1, str2);

	char *result = catchar(str1, str2);

	printf("%s\n", result);
	return 0;
}
