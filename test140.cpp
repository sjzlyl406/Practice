/*************************************************************************
	> File Name: test140.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 09时54分20秒
 ************************************************************************/

/******************************************************************
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > result;
            if (pRoot == nullptr) return result;
            vector<int> path;
             
            vector<TreeNode*> cur, nxt;
            cur.push_back(pRoot);
            path.push_back(pRoot->val);
            result.push_back(path);
             
            while (!cur.empty()) {
                path.clear();
                 
                for (auto &i : cur) {
                    if(i -> left) {
                        nxt.push_back(i -> left);
                        path.push_back(i -> left -> val);
                    }
                    if(i -> right) {
                        nxt.push_back(i -> right);
                        path.push_back(i -> right -> val);
                    }
                }
                if(!path.empty())
                    result.push_back(path);
                 
                cur.clear();
                swap(cur, nxt);
            }
            return result;
        }
     
};

