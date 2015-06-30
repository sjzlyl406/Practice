/*************************************************************************
	> File Name: test2.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年06月30日 星期二 13时25分35秒
 ************************************************************************/

/********************************************************************
 * 输入一棵二叉树的根结点，求树的深度
 * 从根结点到叶节点依次经过的结点（含根、叶结点）形成树的一条路径，
 * 最长路径的长度为树的深度
 * *****************************************************************/
#include<stdio.h>

#define RET_OK 0
#define RET_ERR 1
#define INVALIDPARAMETER 2

#define ret_val_if(p) if(p){											\
		printf("%s:%d warning !"#p" failed.",__func__,__LINE__);		\
		return INVALIDPARAMETER;										\
}																		\

typedef Ret int;

struct BinaryTreeNode
{
	int					m_nValue;
	BinaryTreeNode*		m_pLeft;
	BinaryTreeNode*		m_pRight;
};

/*********** first:dfs ************/
Ret DepthOfBinaryTree(BinaryTreeNode* pRoot, int* depth)
{
	ret_val_if(pRoot == NULL);

	*depth = 0;
	int count = 0;

	dfs(pRoot, depth, count);
	return RET_OK;
}

void dfs(BinaryTreeNode* pRoot, int* depth, int count)
{
	if(*pRoot == NULL) {
		*depth = *depth > count ? *depth : count;
		return;
	}

	dfs(pRoot -> m_pLeft, depth, count+1);
	dfs(pRoot -> m_pRight, depth, count+1);
}


/********* second:recursive ***********/

int DepthOfBinaryTree(BinaryTreeNode* pRoot)
{
	if(pRoot == NULL)
		return 0;

	int nLeft = DepthOfBinaryTree(pRoot -> m_pLeft);
	int nRight = DepthOfBinaryTree(pRoot -> m_pRight);

	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}
