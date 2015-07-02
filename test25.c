/*************************************************************************
	> File Name: test25.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月02日 星期四 21时32分56秒
 ************************************************************************/

/***************************************************************8
 * 一组人（7个），围成一圈，从某人开始数到第3个的人出列，
 * 再接着从下一个人开始数，依次输出出列的人。
 * （报数：共n个人 从1编号，设从第s个人报号，报到m出队，依次输出出队的人。）
 * *************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct _ListNode
{
	int					value;
	struct _ListNode*	Next;
}ListNode;

ListNode* generateList(int n)
{
	if(n <= 0) return NULL;

	ListNode *pHead = (ListNode*)malloc(sizeof(ListNode));
	ListNode *p = pHead;

	int i = 1;
	for(i = 1; i <= n; ++i) {
		(*p).Next = (ListNode*)malloc(sizeof(ListNode));
		p = (*p).Next;
		(*p).value = i;
	}
	(*p).Next = (*pHead).Next;
	
	return (*pHead).Next;
}

int foo(ListNode* pHead, int s, int m)
{
	if(pHead == NULL || s < 1 || m < 1) 
		return -1;

	ListNode *p = pHead;
	while((*((*p).Next)).value != s)
		p = (*p).Next;

	int i = 0;
	while((*p).Next != p) {
		for(i = 1; i < m; ++i) {
			p = (*p).Next;
		}
		ListNode *tmp = (*p).Next;
		(*p).Next = (*tmp).Next;
		free(tmp);
		tmp = NULL;
	}
	return (*p).value;
}
int main(void)
{
	int n, s, m;
	printf("input n, s and m :");
	scanf("%d %d %d", &n, &s, &m);

	ListNode *pHead = generateList(n);
	int cal = foo(pHead, s, m);

	printf("%d\n", cal);

	return 0;
}

