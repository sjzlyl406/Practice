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

/*************** first ******************/

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

/*************** second **************/

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
        int len1(0), len2(0);
        ListNode *cur_p = pHead1;
        for ( ; cur_p != nullptr; cur_p = cur_p -> next) {
            len1++;
        }
        for (cur_p = pHead2; cur_p != nullptr; cur_p = cur_p ->next) {
            len2++;
        }
         
        ListNode *short_p;
        int gap;
        if (len1 > len2) {
            cur_p = pHead1;
            short_p = pHead2;
            gap = len1 - len2;
        } else {
            cur_p = pHead2;
            short_p = pHead1;
            gap = len2 - len1;
        }
         
        for (int i = 0; i < gap; ++i) {
            cur_p = cur_p -> next;
        }
        for ( ; cur_p != nullptr; cur_p = cur_p -> next, short_p = short_p -> next) {
            if (cur_p == short_p) {
                return cur_p;
            }
        }
        return nullptr;
    }
};
