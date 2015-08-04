/*************************************************************************
	> File Name: test126.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月03日 星期一 18时43分52秒
 ************************************************************************/

/*********************************************************************
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *    9  20
 *      /  \
 *      15   7
 * return its level order traversal as:
 *  [
 *   [3],
 *   [9,20],
 *   [15,7]
 *  ]
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 *
 *
 *  OJ's Binary Tree Serialization:
 *  The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
 *
 *  Here's an example:
 *       1
 *      / \
 *     2   3
 *         /
 *        4
 *         \
 *          5
 *  The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 * ******************************************************************/

#include<cstdio>
#include<deque>		//deque
#include<vector>	//vector


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> >ret;
        vector<int> path;
        deque<TreeNode* > curDeq, nextDeq;
        if(root != nullptr)
            curDeq.push_back(root);
        while(!curDeq.empty()) {
            while(!curDeq.empty()) {
                TreeNode *p = curDeq.front();
                curDeq.pop_front();
                path.push_back(p->val);
                if(p -> left)
                    nextDeq.push_back(p->left);
                if(p -> right)
                    nextDeq.push_back(p->right);
            }
            swap(curDeq, nextDeq);
            ret.push_back(path);
            path.clear();
        }
        return ret;
    }
};c
