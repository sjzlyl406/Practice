/*************************************************************************
	> File Name: test29.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 10时08分02秒
 ************************************************************************/

/****************************************************************
 * 高精度的十进制加法
 * ************************************************************/
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MaxNum 100

void plus(char *str1, char *str2)
{
	int minusState = 0;
	int len1 = strlen(str1) - 1;
	int len2 = strlen(str2) - 1;
	int start = 0;

	if(str1[0] == '-') {
		minusState = 1;
		start = 1;
	}

	if(len1 < len2) {
		char *tmp = str1;
		str1 = str2;
		str2 = tmp;
	}
	len1 = strlen(str1) - 1;
	len2 = strlen(str2) - 1;

	int carry = 0;
	int j = len1;
	for(int i = len2; i >= start; --i, --j) {
		str1[j] = str1[j] + str2[i] + carry - '0';
		if(str1[j] > '9') {
			carry = 1;
			str1[j] = (str1[j] - '0') % 10 + '0';
		}
		else 
			carry = 0;
	}
	while(j >= start && carry == 1) {
		str1[j] = str1[j] + carry;
		if(str1[j] > '9') {
			carry = 1;
			str1[j] = '0';
		}
		j--;
	}

	printf("%c", str1[0]);
	if(carry)
		printf("%d", carry);
	printf("%s\n", str1+1);
}

int main(void)
{
	char str1[MaxNum] = {0}, str2[MaxNum] = {0};
	scanf("%s %s", str1, str2);

	plus(str1, str2);


	return 0;
}
