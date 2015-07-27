/*************************************************************************
	> File Name: test107.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月26日 星期日 22时52分45秒
 ************************************************************************/

/*******************************************************************
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * *****************************************************************/
#include<iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode dummy(-1);
        ListNode *p = &dummy;
        
        int carry = 0;  //进位
        
        while(l1 != NULL && l2 != NULL) {
            int cur_sum = l1->val + l2->val + carry;
            if(cur_sum > 9) {
                carry = 1;
                cur_sum %= 10;
            }
            else carry = 0;
            ListNode *tmp = new ListNode(cur_sum);
            p -> next = tmp;
            p = p -> next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        //ll指向还没有遍历结束的链表
        ListNode *ll = NULL;
        if(l1 != NULL) ll = l1;
        if(l2 != NULL) ll = l2;
        
        while(ll != NULL) { 
            int cur_sum = ll -> val + carry;
            if(cur_sum > 9) {
                carry = 1;
                cur_sum %= 10;
            }
            else carry = 0;
            ListNode *tmp = new ListNode(cur_sum);
            p -> next = tmp;
            p = p ->next;
            
            ll = ll-> next;
        }
        if(carry) { //carry != 0
            ListNode *tmp = new ListNode(1);
            p -> next = tmp;
        }
        return dummy.next;
    }
};
