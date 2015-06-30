/*************************************************************************
	> File Name: test11.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 20时05分10秒
 ************************************************************************/

/****************************************************************
 * 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的
 * A为1，J为11，Q为12，K为13，而大小王看作任意数字。
 * *************************************************************/
#include<stdio.h>
#include<algorithm>  //sort

int isCursesive(int *array, int len)
{
	if(array == NULL && len != 5) return 0;

	std::sort(array, array+len);
	int CountZero = 0;
	int np = 0;
	while( array[np] == 0 ) {
		CountZero++;
		np++;
	}
	int i = np;
	for(i = np+1; i < len; ++i)
		if(array[i-1] == array[i])
			return false;

	int dif = array[len-1] - array[np] - np;

	if(dif + np <= 4)
		return 1;
	else
		return 0;
}
int main(void)
{
	int array[5] = {0};
	int i = 0;
	for(i = 0; i < 5; ++i)
		scanf("%d", &array[i]);

	if(isCursesive(array, 5))
		printf("true!");
	else
		printf("false!");
	return 0;
}
