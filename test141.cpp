/*************************************************************************
	> File Name: test141.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 09时54分48秒
 ************************************************************************/

/******************************************************************
 * 请实现一个函数按照之字形打印二叉树，
 * 即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
 * 第三行按照从左到右的顺序打印，其他行以此类推。
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
        vector<TreeNode*> cur, nxt;
        vector<vector<int> > result;
        if (pRoot == nullptr) return result;     
         
        vector<int> path;
        cur.push_back(pRoot);
        ListNode* p;
        int loop(0);
         
        while (!cur.empty()) {
             
            for (auto &i : cur) {
                if (i -> left)
                    nxt.push_back(i -> left);
                if (i -> right)
                    nxt.push_back(i -> right);
            }
            if (loop & 0x01)
                reverse(cur.begin(), cur.end());
            for (auto &i : cur) {
                path.push_back(i -> val);
            }
            result.push_back(path);
            path.clear();
             
            cur.clear();
            loop = loop + 1;
            swap (cur, nxt);
        }
        return result;
    }
     
};
