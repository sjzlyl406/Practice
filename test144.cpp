/*************************************************************************
	> File Name: test144.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 10时01分42秒
 ************************************************************************/

/******************************************************************
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == nullptr) return nullptr;
         
        ListNode dummy(-1);
        dummy.next = pHead;
        ListNode *cur_p(&dummy), *pre_p(pHead);
         
        for ( ; pre_p != nullptr && pre_p -> next != nullptr; ) {
            if (pre_p -> val == pre_p -> next -> val) {    //重复
                while (pre_p -> next != nullptr && pre_p -> val == pre_p -> next -> val) {
                    pre_p = pre_p -> next;
                }
                pre_p = pre_p -> next;
                ListNode *tmp = cur_p -> next;
                while (tmp != pre_p) {                   
                    cur_p -> next = tmp -> next;
                    delete tmp;
                    tmp = cur_p -> next;
                }
            }
            else {
                cur_p = pre_p;
                pre_p = pre_p -> next;
            }
        }
         
        return dummy.next;
    }
};
