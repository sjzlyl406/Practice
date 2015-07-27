/*************************************************************************
	> File Name: test111.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月27日 星期一 19时06分36秒
 ************************************************************************/

/***********************************************************************
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 * *******************************************************************/


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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* p = &dummy;
        while(p->next != NULL && p->next->next != NULL) {
            ListNode *tmp = p -> next;
            ListNode *q = tmp -> next;
            tmp -> next = q ->next;
            q -> next = tmp;
            p -> next = q;
            p = tmp;
        }
        return dummy.next;
    }
};

