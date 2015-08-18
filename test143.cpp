/*************************************************************************
	> File Name: test143.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 09时55分53秒
 ************************************************************************/

/******************************************************************
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点
 * 并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 * ***************************************************************/
#include<iostream>
using namespace std;


/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
         
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == nullptr) return pNode;
         
        TreeLinkNode* p;
        if (pNode -> right != nullptr) { //右子树最小值
            p = pNode -> right;
            while (p -> left != nullptr) {
                p = p -> left;
            }    
        }
        else {                  //沿着父节点上找，不是右节点的父节点
            p = pNode;           
            while (p -> next != nullptr && p -> next -> right == p) {
                p = p -> next;
            }
            if (p -> next == nullptr)
                return nullptr;
            else {
                p = p -> next;
            }
        }
         
        return p;
    }
};
