/*************************************************************************
	> File Name: test161.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 10时14分38秒
 ************************************************************************/

/******************************************************************
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 * ***************************************************************/
#include<iostream>
using namespace std;
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == nullptr) return true;
         
        int left = depth(pRoot -> left);
        int right = depth(pRoot -> right);
         
        if (fabs(left - right) > 1)
            return false;
         
        return IsBalanced_Solution(pRoot -> left) &&
            IsBalanced_Solution(pRoot -> right);
    }
private:
    int depth(TreeNode *node) {
        if (node == nullptr)
            return 0;
         
        int left = depth (node -> left);
        int right = depth (node -> right);
         
        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
};
