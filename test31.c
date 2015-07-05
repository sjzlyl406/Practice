/*************************************************************************
	> File Name: test31.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 11时22分36秒
 ************************************************************************/

/****************************************************************
 * 通过键盘输入一串小写字母(a~z)组成的字符串。请编写一个字符串过滤程序，
 * 若字符串中出现多个相同的字符，将非首次出现的字符过滤掉。
 * 比如字符串“abacacde”过滤结果为“abcde”。
 * *************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define asciilen 256

char *filter(char* str)
{
	if(str == NULL) return NULL;

	int len = strlen(str);
	char *result = (char*)malloc(len * sizeof(char));

	char map[asciilen] = {0};
	memset(map, 0, asciilen * sizeof(char));

	int i = 0, p = 0;
	for(i = 0; i < len; ++i) {
		if(map[str[i]] == 0){
			map[str[i]] = 1;
			result[p++] = str[i];
		}
	}

	return result;
}

int main(void)
{
	char str[asciilen] = {0};
	scanf("%s", str);

	char *result = filter(str);

	printf("%s\n", result);

	return 0;
}
