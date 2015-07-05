/*************************************************************************
	> File Name: test41.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月03日 星期五 17时32分47秒
 ************************************************************************/

/**********************************************************
 * 给定一个字符串,实现一个函数,按下述方式输出字符串： 
 * 如果此字符的下一个字符和此字符不一样，原样输出此字符， 
 * 否则先输出此字符，再输出此字符连续出现的次数（次数不大于9）。 
 * 例如,字符串ABBCCCDEDFFF，输出的结果为AB2C3DEDF3。 
 * 不用考虑溢出问题，不能使用任何I/O函数。
 * ******************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxLength 100

char* Change(char *cc) 
{
	int len = strlen(cc);
	char * result = (char*)malloc((len+1)*sizeof(char));
	memset(result, 0, (len+1)*sizeof(char));
	if (cc != NULL) {
		char *p = result;
		*p++ = *cc;
		char *c = cc+1;
		int count = 1;

		while(*c != '\0') {
			if(*c != *(c-1)) {
				if(count > 1) {
					*p++ = count+'0';
					count=1;
				}
				*p++ = *c;
			}
			else {
				count++;
			}
			c++;
		}
		if(count > 1){
			*p++ = count +'0';
		}
	}
	return result;
}

int main(void)
{
	char cc[MaxLength] = {0};
	char *result = NULL;
	printf("input a string:");

	scanf("%s", cc);

	result = Change(cc);

	printf("%s\n", result);

	return 0;
}
