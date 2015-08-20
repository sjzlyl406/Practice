/*************************************************************************
	> File Name: test163.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月20日 星期四 15时40分54秒
 ************************************************************************/

/******************************************************************
 * 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        int depth(0);
        if (pRoot == nullptr)
            return depth;
         
        dfs(pRoot, 0, depth);
         
        return depth;
    }
private:
    void dfs (TreeNode* node, int loop, int &depth) {
        if (node -> left == nullptr && node -> right == nullptr) {
            if (loop + 1 > depth) {
                depth = loop + 1;
            }
            return ;
        }
         
        if (node -> left)
            dfs (node -> left, loop + 1, depth);
        if (node -> right)
            dfs (node -> right, loop + 1, depth);
    }
};
