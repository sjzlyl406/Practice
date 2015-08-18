/*************************************************************************
	> File Name: test139.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月18日 星期二 09时47分58秒
 ************************************************************************/

/*****************************************************************
 * 请实现两个函数，分别用来序列化和反序列化二叉树
 *
 * **************************************************************/
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
    char* Serialize(TreeNode *root) {   
        if (root == nullptr) return nullptr;
        string str;
        vector<TreeNode*> cur, nxt;
         
        cur.push_back(root);
        stringstream os;
        os << root -> val << ' ';
         
        while (!cur.empty()) {  //按行保存成一个序列
             
            for (auto &i : cur) {
                 
                if (i -> left) {
                    os << i -> left -> val << ' ';
                    nxt.push_back(i -> left);
                } else {
                    os << '#' << ' ';
                }
                 
                if (i -> right) {
                    os << i -> right -> val << ' ';
                    nxt.push_back(i -> right);
                } else {
                    os << '#' << ' ';
                }
            }           
            cur.clear();
            swap(cur, nxt);
        }
         
        getline(os, str);   
         
        char *result = new char[str.size()+1];
        strcpy(result, str.c_str());
        return result;
    }
    TreeNode* Deserialize(char *str) {
        if (str == nullptr) return nullptr;
         
        TreeNode dummy(-1);
        vector<TreeNode**> vec;
        string str_tmp(str);
        stringstream os(str_tmp);
        TreeNode *tmp;
         
        vec.push_back(&dummy.left);
        size_t i = 0;
        while (os >> str_tmp) {
            if (str_tmp == "#") {   //叶子节点
                tmp = nullptr;
                *vec[i++] = nullptr;
            }
            else {              //不是叶子节点               
                tmp = new TreeNode(atoi(str_tmp.c_str()));
                *vec[i++] = tmp;
                vec.push_back(&(tmp->left));
                vec.push_back(&(tmp->right));
            }
        }
         
        return dummy.left;
    }
};
