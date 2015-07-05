/*************************************************************************
	> File Name: test32.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 14时37分39秒
 ************************************************************************/

/*****************************************************************
 * 通过键盘输入一串小写字母(a~z)组成的字符串。请编写一个字符串压缩程序，将字符串中连续出席的重复字母进行压缩，并输出压缩后的字符串。
 * 压缩规则：
 * 1. 仅压缩连续重复出现的字符。比如字符串"abcbc"由于无连续重复字符，压缩后的字符串还是"abcbc".
 * 2. 压缩字段的格式为"字符重复的次数+字符"。例如：字符串"xxxyyyyyyz"压缩后就成为"3x6yz"
 * **************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* Press(char* str)
{
	if(str == NULL) return NULL;
	int len = strlen(str);

	char *result = (char*)malloc((len+1) * sizeof(char));
	memset(result, 0, (len+1)*sizeof(char));
	size_t p = 0;

	int count = 1;
	size_t i = 0;
	for(i = 1; i < len+1; ++i) {
		if(str[i] == str[i-1]){
			count++;
		}
		else{
			if(count > 1)
				result[p++] = count + '0';
			result[p++] = str[i-1];
			count = 1;
		}
	}

	return result;
}
int main(void)
{
	char str[100] = {0};
	scanf("%s", str);

	char *result = (char*)malloc(100 * sizeof(char));
	memset(result, 0, 100 * sizeof(char));
	result = Press(str);

	printf("%s\n", result);

	return 0;
}
