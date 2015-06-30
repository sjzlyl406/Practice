/*************************************************************************
	> File Name: test9.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 17时11分41秒
 ************************************************************************/

/****************************************************************
 * 字符串左旋操作是把字符串前面的若干字符转移到字符串的尾部。
 * 输入字符串“abcdefg”和2，返回左旋2位后得到的结果“cdefgab”
 * *************************************************************/
#include<stdio.h>
#include<string.h>

void Reverse(char *pleft, char *pright)
{
	if(pleft == NULL || pright == NULL)
		return;

	while(pleft < pright) {
		char tmp = *pleft;
		*pleft = *pright;
		*pright = tmp;

		pleft ++; pright --;
	}
}
void LeftRotation(char *str, int k)
{
	if(str == NULL || k <= 0) return;

	int len = strlen(str);
	if( len > k) {
		Reverse(str, str+len-1);

		Reverse(str, str+len-k-1);
		Reverse(str+len-k, str+len-1);
	}
}
int main(void)
{
	char str[] = "abcdefg";
	LeftRotation(str, 2);

	printf("%s\n", str);

	return 0; 
}
