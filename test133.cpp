/*************************************************************************
	> File Name: test.c
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年08月13日 星期四 21时54分57秒
 ************************************************************************/

/****************************************************
 * 通过前序中序建立二叉树
 * **************************************************/
#include<cstdio>
#include<cctype>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
		size_t length_of_pre = pre.size();
        size_t length_of_in = pre.size();
        return foo(pre, 0, length_of_pre,
                   in, 0, length_of_in);
    }
    
private:
    struct TreeNode* foo(const vector<int> &pre, 
                         size_t left_index_of_pre, 
                         size_t right_index_of_pre,
                         const vector<int> &in,
                         size_t left_index_of_in,
                         size_t right_index_of_in) {
        if(left_index_of_pre == right_index_of_pre) return nullptr;//空值判断
	/*	for(int i = 0; i < pre.size(); i++) {
			printf("%d\t", pre[i]);
			printf("%d\t", in[i]);
		} */
		printf("\n");
        
        int value = pre[left_index_of_pre];
        struct TreeNode *new_tree_node = new TreeNode(value);	//new node	
        size_t offset(0);	
        
   //     if(left_index_of_pre + 1 != right_index_of_in) {	//多个节点											//多个节点
            offset = distance(in.begin(), find(in.begin(), in.end(), value))
                - left_index_of_in;
            
            new_tree_node -> left = foo(pre, left_index_of_pre+1, 
                                        left_index_of_pre+offset+1,
                                        in, left_index_of_in,
                                        left_index_of_in+offset);
            
            new_tree_node -> right = foo(pre, left_index_of_pre+offset+1,
                                         right_index_of_pre,
                                         in, left_index_of_in+offset+1,
                                         right_index_of_in);
     //   }
        return new_tree_node;
    }
};

void cout(TreeNode* root) {
	if(root != nullptr) {
		printf("%d\t", root->val);
		cout(root->left);
		cout(root->right);
	}
}

int main(void) {
	Solution ss;
	int pre[] = {1,2,4,3,5,6};
	int in[] = {4,2,1,5,3,6};
	vector<int> pree(pre, pre+6);
	vector<int> inn(in, in+6);
	TreeNode *root = ss.reConstructBinaryTree(pree, inn);
	cout(root);
	printf("\n");
	return 0;
}
