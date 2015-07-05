/*************************************************************************
	> File Name: test26.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月02日 星期四 22时06分38秒
 ************************************************************************/

/******************************************************************
 * 出一个链表和一个数k，比如链表1→2→3→4→5→6，k=2，
 * 则翻转后2→1→4→3→6→5，若k=3,翻转后3→2→1→6→5→4，
 * 若k=4，翻转后4→3→2→1→6→5，用程序实现。
 * ****************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct _ListNode
{
	int					value;
	struct _ListNode	*next;
}ListNode;

ListNode* generateList(int n)
{
	if(n <= 0) return NULL;

	ListNode *pHead = (ListNode*)malloc(sizeof(ListNode));
	ListNode *p = pHead;

	int i = 1;
	for(i = 1; i <= n; ++i) {
		(*p).next = (ListNode*)malloc(sizeof(ListNode));
		p = (*p).next;
		(*p).value = i;
	}
	(*p).next = NULL;
	
	return (*pHead).next;
}
ListNode* Reverse(ListNode* pHead, int k)
{
	if(pHead == NULL || k < 1) return NULL;

	ListNode dummy;
	dummy.next = pHead;
	ListNode *p = &dummy;
	ListNode *left = p;

	while(p -> next != NULL) {
		for(int i = 0;p->next != NULL && i < k; ++i) {
			p = p -> next;
		}
		ListNode *nextp = NULL; int i = 0;
		while(left->next != p) {
			ListNode *tmp = left -> next;
			left -> next = tmp -> next;
			tmp -> next = p -> next;
			p -> next = tmp;
			if(i == 0)
				nextp = tmp;
			i++;
		}
		p = left = nextp;
	}

	return dummy.next;
}
void Prinf(ListNode* pHead)
{
	if(pHead == NULL) return;
	while(pHead != NULL) {
		printf("%d\t", pHead->value);
		pHead = pHead -> next;
	}
	printf("\n");
}

int main(void)
{
	int k, n;
	scanf("%d %d",&k, &n);

	ListNode *pHead = NULL;
	pHead = generateList(k);

	Prinf(pHead);

	pHead = Reverse(pHead, n);

	Prinf(pHead);

	return 0;
}
