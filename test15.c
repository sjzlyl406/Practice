/*************************************************************************
	> File Name: test15.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月01日 星期三 10时56分08秒
 ************************************************************************/

/*********************************************************
 * 编写StrToInt函数，实现字符串到正数数字的转换。
 * *******************************************************/

#include<stdio.h>
#include<ctype.h>

typedef int Ret;

#define INVALIDPARAMETER 2
#define RET_ERR 1
#define RET_OK 0

Ret StrToInt(char *str, int *result)
{
	Ret status = RET_OK;

	if(str == NULL || result == NULL)
		status = INVALIDPARAMETER;
	else {
		*result = 0;
		char *p = str;
		int minus = 0;

		while(*p != '\0' && !(isdigit(*p) || *p == '+' || *p == '-'))
			p++;
		if(*p == '+' || *p == '-'){
			if( *p == '-' ) {
				minus = 1;
			}
			p++;
		}

		while(*p != '\0' && isdigit(*p)){
			if(*result > 0x7FF8){
				status = RET_ERR;
				break;
			}
			*result = *result * 10 + ((int)(*p) - '0');
			p++;
		}
		if(minus == 1)
			*result = 0 - *result;
	}
		
	return status;
}
int main(void)
{
	char str[20];
	scanf("%s", str);

	int result;

	if(StrToInt(str, &result) == RET_OK)
		printf("%s : %d\n", str, result);
	else
		printf("invalid parameter\n");

	return 0;
}
