/*************************************************************************
	> File Name: test145.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 10时02分05秒
 ************************************************************************/

/******************************************************************
 * 一个链表中包含环，请找出该链表的环的入口结点。
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode *fast = pHead, *slow = pHead;
        //快慢指针
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (slow == fast)
                break;
        }
        //找到相遇点
        fast = pHead;
        while (fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }
        if (fast -> next == nullptr)
            return nullptr;
        return fast;
    }
};
