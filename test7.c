/*************************************************************************
	> File Name: test7.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 15时55分33秒
 ************************************************************************/

/***************************************************
 * 输入一个正数s,打印出所有和为s的连续正数序列（至少包含两个数）
 * 如输入15， 1+2+3+4+5=4+5+6=7+8=15
 * 所以输出 1~5、4~6、7~8
 * ************************************************/
#include<stdio.h>

int SumOfConsecutiveNum(int left, int right)
{
	int len = right - left + 1;
	int tmp = left + right;

	int result = 0, i = 0;
	for(i = 0; i < (len >> 1); ++i)
		result += tmp;
	if(len & 0x1)
		result += (tmp >> 1);

	return result;
}
/*********** first:O(n^3) ************/
void PrintConsecutiveNum1(int s)
{
	if(s < 3) 
		return;

	int left = 1, right = 0;
	for(left = 1; left <= (s>>1); ++left) {
		for(right = left+1; right < s; ++right) {
			int tmp = SumOfConsecutiveNum(left, right);
			if(tmp == s) {
				int i = left;
				for(i = left; i < right; ++i)
					printf(" %d +", i);
				printf(" %d = %d \n", i, s);
				break;
			}
		}
	}

	return;
}
/************ second:O(n^2) *************/
void PrintConsecutiveNum2(int s)
{
	if(s < 3)
		return;
	int left = 1, right = 2;

	while(left < right) {
		int tmp = SumOfConsecutiveNum(left, right);
		if(tmp == s) {
			int i = left;
			for(i = left; i < right; ++i)
				printf(" %d +", i);
			printf(" %d = %d\n", i, s);
			right++;
		}	
		else if( tmp < s )
			right++;
		else
			left++;
	}
	return;
}
/********* third:O(n) ***********/
void PrintConsecutiveNum3( int s ) 
{
	if(s < 3)
		return;
	int left = 1, right = 2;
	int cursum = left + right;

	while(left < right) {
		if(cursum == s) {
			int i = left;
			for(i = left; i < right; ++i)
				printf("%d + ", i);
			printf("%d = %d\n", i, s);
			right++; cursum += right;
		}
		else if( cursum  < s ) {
			right ++; cursum += right;
		}
		else {
			cursum -= left; left++;
		}
	}
}

int main(void)
{
	int num = 15;
	PrintConsecutiveNum3(num);
	return 0;
}
