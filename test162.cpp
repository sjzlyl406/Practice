/*************************************************************************
	> File Name: test162.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 19时08分40秒
 ************************************************************************/

/******************************************************************
 * 输入两个链表，找出它们的第一个公共结点。
 * ***************************************************************/
#include<iostream>
using namespace std;


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        stack<ListNode*> stack1, stack2;
        ListNode *p1 = pHead1, *p2 = pHead2;

        for ( ; p1 != nullptr; p1 = p1 -> next) stack1.push(p1);
        for ( ; p2 != nullptr; p2 = p2 -> next) stack2.push(p2);
        
        p1 = nullptr; p2 = nullptr;
        
        while(stack1.size() != 0 && stack2.size() != 0) {
            if (stack1.top() != stack2.top()) {
                return p1;
            }
            p1 = stack1.top(); 	p2 = stack2.top();
            stack1.pop();		stack2.pop();
        }
        return p1;
    }
};
