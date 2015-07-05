/*************************************************************************
	> File Name: test44.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月05日 星期日 20时19分26秒
 ************************************************************************/

/*********************************************************
 * 字符串匹配问题，给定两个字符串，求字符串2在字符串1中的最先匹配结果。
 * 字符串2中可以存在'*'符号，且该符号可以代表任意字符，
 * 即字符串2中存在通配符。
 * e.g. 输入：abcdefghabef, a*f    输出：abcdef''
 * *******************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MaxLength 100

int isPiPei(char c1, char c2)
{
	if(c1 == c2)
		return 1;
	else if(c2 == '*')
		return 2;
	else
		return 0;
}
char *foo(char* str1, char* str2)
{
	if(str1 == NULL || str2 == NULL) return NULL;
	char *result = (char*)malloc(MaxLength * sizeof(char));
	memset(result, 0, MaxLength*sizeof(char));
	char *left = str1, *right;
	char *p = str2;

	while(*left != '\0') {
		if(isPiPei(*left, *p) > 0) {
			char *c = left;
			while(isPiPei(*c, *p) > 0) {
				if(isPiPei(*c, *p) == 1) {
					c++;	p++;
				}
				else if( isPiPei(*c, *p) == 2) {
					if( isPiPei(*(c+1), *(p+1)) == 1) {
						c++; p++;
					}
					else
						c++;
				}
				if(*p == '\0') {
					right = c;
					char *rp = result;
					while(left != right) {
						*rp++ = *left++;
					}
					return result;
				}
				if(*c == '\0') {
					return result;
				}
			}

			p = str2;
		}
		left++;
	}
	return result;

}
int main(void)
{
	char input[MaxLength] = {0};
	printf("input a string:");
	scanf("%s", input);

	char str[MaxLength] = {0};
	printf("input another string:");
	scanf("%s", str);
	
	char *result = foo(input, str);

	printf("%s\n", result);

	return 0;
}
