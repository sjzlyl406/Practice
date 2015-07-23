/*************************************************************************
	> File Name: test101.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月23日 星期四 22时55分50秒
 ************************************************************************/

/**********************************************************************
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.''
 * *****************************************************************/
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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, -2147483649LL, 2147483649LL);
    }
    
private:
    bool isValid(TreeNode* root, long long val_min, long long val_max) {
        if(root == NULL) return true;
        
        return root->val > val_min && root->val < val_max &&
            isValid(root->left, val_min, root->val) && 
            isValid(root -> right, root->val, val_max);
    }
};
