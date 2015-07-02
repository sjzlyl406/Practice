/*************************************************************************
	> File Name: test24.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月02日 星期四 21时18分36秒
 ************************************************************************/

/******************************************************************8
 * 输入一串字符，只包含“0-10”和“，”找出其中最小的数字和最大的数字
 * （可能不止一个），输出最后剩余数字个数。
 * ***************************************************************/
#include<stdio.h>
#include<ctype.h>
#include<limits.h>

int main(void)
{
	char str[100] = {0};
	scanf("%s", str);

	char *p = str;
	int count = 0;
	int minNum = INT_MAX, maxNum = INT_MIN;
	int minc = 0, maxc = 0;

	while(*p != '\0') {
		if(isdigit(*p)) {
			count++;
			if(*p > maxNum) {
				maxNum = *p;
				maxc = 1;
			}
			else if( *p == maxNum )
				maxc++;
			if(*p < minNum) {
				minNum = *p;
				minc = 1;
			}
			else if(*p == minNum)
				minc++;
		}
		++p;
	}
	int result = count - maxc - minc;

	printf("result is %d.\n", result);

	return 0;
}

