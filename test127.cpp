/*************************************************************************
	> File Name: test127.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月03日 星期一 21时22分39秒
 ************************************************************************/

/*********************************************************************
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
 *
 *     1
 *    / \
 *   2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 *
 * Return the sum = 12 + 13 = 25.
 * ******************************************************************/
#include<iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<cstdlib>
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int sum = 0;
        sumNum(root, 0, sum);
        return sum;
    }
    void sumNum (TreeNode* root, int path, int &sum) {
        if(root->left == nullptr && root->right == nullptr)
            sum += path*10+root->val;
        if(root->left)
            sumNum(root->left, path*10+root->val, sum);
        if(root -> right)
            sumNum(root->right, path*10+root->val, sum);
    }
};
