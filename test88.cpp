/*************************************************************************
	> File Name: test88.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月20日 星期一 21时55分18秒
 ************************************************************************/

/**********************************************************************
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse
 * order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * *******************************************************************/
#include<cstdio>
#include<algorithm>

struct ListNode {
	int value;
	ListNode *next;
	ListNode(int m) : value(m), next(NULL) {}
};
class List {
	public:
		List(int *array, int len) : pHead(0) { generate(array, len); }
		~List() { delete pHead; }

		void Walk(void);
		const ListNode* getHead() const { return pHead; }
	private:
		void generate(int *array, int len);

	private:
		ListNode *pHead;
};
void List::generate(int *array, int len){
	ListNode *p = new ListNode(0);
	pHead = p;
	for(int i = 0; i < len; ++i) {
		p->next = new ListNode(array[i]);
		p = p->next;
	}
	pHead = pHead->next;
}
void List::Walk(void)
{
	ListNode *p = pHead;
	while(p != NULL) {
		printf("%d\t", p->value);
		p = p -> next;
	}
	printf("\n");
}

ListNode* foo(const List &mylist1, const List &mylist2) {
	ListNode *ret = new ListNode(-1), *p = ret;
	const ListNode *pmax(mylist1.getHead()), *pmin(mylist2.getHead());
	size_t len1(0), len2(0);
	while(pmax != NULL) {pmax = pmax->next; ++len1;}
	while(pmin != NULL) {pmin = pmin->next; ++len2;}

	if(len2 > len1) {
		pmax = mylist2.getHead();
		pmin = mylist1.getHead();
	}
	else {
		pmax = mylist1.getHead();
		pmin = mylist2.getHead();
	}

	int carry(0);
	for(;pmin != NULL; pmax = pmax->next,pmin = pmin->next) {
		int sum = carry + pmax->value + pmin -> value;
		if(sum < 10) {
			carry = 0;
		}
		else {
			carry = sum / 10;
			sum = sum % 10;
		}
		p -> next = new ListNode(sum);
		p = p -> next;
	}
	for(;pmax != NULL; pmax = pmax -> next) {
		int sum = carry + pmax -> value;
		if(sum < 10)
			carry = 0;
		else {
			carry = 1;
			sum = sum % 10;
		}
		p -> next = new ListNode(sum);
		p = p -> next;
	}
	if(carry) {
		p->next = new ListNode(1);
	}
	return ret->next;
}

int main (void)
{
	int num1[] = {2,4,8};
	int num2[] = {5,6,4,9};
	List mylist1(num1, 3), mylist2(num2, 4);
	mylist1.Walk();
	mylist2.Walk();
	
	ListNode *pHead = foo(mylist1, mylist2);

	while(pHead != NULL) {
		printf("%d\t", pHead->value);
		pHead = pHead -> next;
	}
	printf("\n");
	return 0;
}
