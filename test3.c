/*************************************************************************
	> File Name: test3.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 13时58分45秒
 ************************************************************************/

/******************************************************************
 * 输入一颗二叉树的根结点，判断该树是不是平衡二叉树
 * 如果二叉树中任意结点左右子树深度相差不超过1，则该树是平衡二叉树
 * ****************************************************************/
#include<stdio.h>

#define RET_OK 0
#define RET_ERR 1
#define INVALIDPARAMETER 2

#define ret_val_if(p) if(p){										\
		printf("%s:%d warning !"#p" failed.",__func__,__LINE__);		\
		return INVALIDPARAMETER;										\
}																	\

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRigth;
};
int TreeDepth(BinaryTreeNode* pRoot)
{
	if(pRoot == NULL)
		return 0;

	int nLeft = TreeDepth(pRoot -> m_pLeft);
	int nRight = TreeDepth(pRoot -> m_pRigth);

	return (nLeft > nRight) ? (nLeft+1) : (nRight+1) ;
}

/******* first:O(n^2) ********/
bool IsBalanced(BinaryTreeNode* pRoot)
{
	if(pRoot == NULL)
		return true;

	int nleft = TreeDepth(pRoot -> m_pLeft);
	int nright = TreeDepth(pRoot -> m_pRigth);

	int dif = (nleft > nright) ? (nleft - nright) : (nright - nleft) ;

	if(dif > 1)
		return false;

	return IsBalanced(pRoot -> m_pLeft) && IsBalanced(pRoot -> m_pRigth);
}

/*********** second:O(n) ************/
bool IsBalanced(BinaryTreeNode* pRoot, int *depth);
bool IsBalanced(BinaryTreeNode* pRoot)
{
	int depth = 0;
	return IsBalanced(pRoot, *depth);
}
bool IsBalanced(BinaryTreeNode* pRoot, int *depth) 
{
	if(pRoot == NULL) {
		*depth = 0;
		return true;
	}

	int nLeft = 0, nright = 0;
	if(IsBalanced(pRoot -> m_pLeft, nLeft) && 
			IsBalanced(pRoot -> m_pRigth, nRight)) {
		int dif = (nLeft > nRight) ? (nLeft - nRight) : (nRight - nLeft) ;
		if(dif <= 1) {
			*depth = 1 + (nLeft > nRight ? nLeft : nRight);
			return true;
		}
	}

	return false;
}
