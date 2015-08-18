/*************************************************************************
	> File Name: test142.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 09时55分26秒
 ************************************************************************/

/******************************************************************
 * 请实现一个函数，用来判断一颗二叉树是不是对称的。
 * 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的
 * ***************************************************************/
#include<iostream>
using namespace std;



/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == nullptr) return true;
        return mirro(pRoot -> left, pRoot -> right);
    }
private:
    bool mirro (TreeNode* leftt, TreeNode* rightt) {
        if (leftt == nullptr && rightt == nullptr) return true;
        if (leftt == nullptr && rightt != nullptr) return false;
        if (leftt != nullptr && rightt == nullptr) return false;
        if (leftt -> val != rightt -> val) return false;
         
        return mirro(leftt -> left, rightt -> right) &&
            mirro(leftt -> right, rightt -> left);
    }
 
};
