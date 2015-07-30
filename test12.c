/*************************************************************************
	> File Name: test12.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 20时55分39秒
 ************************************************************************/

/**********************************************************************
 * 0，1，...，n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里
 * 删除第m个数字。求出这个圆圈剩下最后一个数字。
 * ********************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode_
{
	int			Value;
	struct ListNode_	*Next;
}ListNode;

ListNode* GenerateList(int n)
{
	if(n <= 0) return NULL;
	ListNode *pHead = (ListNode*)malloc(sizeof(ListNode));
	ListNode* curp = pHead;


	int i = 0;
	for(i = 0; i < n; ++i) {
		curp -> Next = (ListNode*)malloc(sizeof(ListNode));
		curp = curp -> Next;
		curp -> Value = i;
	}
	curp -> Next = pHead -> Next;
	free(pHead);
	pHead = curp -> Next;
	return pHead;
}

int foo(ListNode *pHead, int m)
{
	if(pHead == NULL || m < 0) return -1;

	int i = 0;
	ListNode *curP = pHead;
	while(curP -> Next != pHead)
		curP = curP -> Next;

	while(curP -> Next != curP) {
		for(i = 1; i < m; ++i) {
			curP = curP -> Next;
		}
		ListNode* tmp = curP -> Next;
		curP -> Next = tmp -> Next;
		free(tmp);
		tmp = NULL;
	}

	return curP -> Value;
}
int main(void)
{
	int input = 0, m = 0;
	scanf("%d %d", &input, &m);

	ListNode *pHead = GenerateList(input);

	printf("generate done!\n");

	printf("dddd : %d\n", foo(pHead, m));

	return 0;
}
