/*************************************************************************
	> File Name: test46.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月05日 星期日 21时38分59秒
 ************************************************************************/

/*********************************************************
 * 统计字符串中数字出现的次数，最大次数的统计出来
 * 举例：输入：323324423343输出：3,6
 * ********************************************************/
#include<stdio.h>
#include<ctype.h>

#define MaxLength 100

int main(void)
{
	char str[MaxLength] = {0};
	printf("input a number:");
	scanf("%s", str);

	char map[10] = {0};
	char *p = str;
	while(*p != '\0') {
		if(isdigit(*p)) 
			map[*p-'0']++;
		p++;
	}
	int maxcount = -1;
	int num = 0;
	int i = 0;
	for(i = 0; i < 10; ++i) {
		if(maxcount < map[i]) {
			maxcount = map[i];
			num = i;
		}
	}
	printf("%d, %d", num, maxcount);

	return 0;
}

