/*************************************************************************
	> File Name: test138.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 09时45分06秒
 ************************************************************************/

/**********************************************************************
 * 给定一颗二叉搜索树，请找出其中的第k大的结点。
 * 例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，
 * 按结点数值大小顺序第三个结点的值为4。
 * ********************************************************************/
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
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if (pRoot == nullptr || k < 1 ) return nullptr;
      
        inorder(pRoot);
         
        if (k > vec.size()) return nullptr;
         
        return vec[k-1];
    }
private:
    void inorder(TreeNode* root) {
        if (root != nullptr) {
            inorder (root -> left);
            vec.push_back(root);
            inorder (root -> right);
        }
    }
     
private:
    vector<TreeNode*> vec;
};
