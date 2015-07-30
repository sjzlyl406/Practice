/*************************************************************************
	> File Name: test119.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月28日 星期二 23时32分10秒
 ************************************************************************/

/******************************************************************
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 *
 * [
 *   ["ABCE"],
 *   ["SFCS"],
 *   ["ADEE"]
 * ]
 *       word = "ABCCED", -> returns true,
 *       word = "SEE", -> returns true,
 *       word = "ABCB", -> returns false.
 * **************************************************************/
#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;

class Solution {
private:
    bool bfs(string word, int index, vector<vector<char> >&board, size_t i, size_t j) {
        // 从board[i][j]搜索是否匹配word
        if(index == word.size()) return true;
        
        bool b_up =false, b_down =false, b_left =false, b_right = false;
        //up
        if(i > 0 && word[index] == board[i][j])
            b_up = dfs(word, index+1, board, i-1, j);
        //down
        if(i+1 < board.size() && word[index] == board[i][j])
            b_down = dfs(word, index+1, board, i+1, j);
            
        //left
        if(j > 0 && word[index] == board[i][j])
            b_left = dfs(word, index+1, board, i, j-1);
        //right
        if(j+1 < board[0].size() && word[index] == board[i][j])
            b_right = dfs(word, index+1, board, i, j+1);
        
        return b_up || b_down || b_left || b_right;
    }
    bool dfs(string word, int index, vector<vector<char> >&board, size_t i, size_t j) {
        // 从board[i][j]搜索是否匹配word
        if(index == word.size()) return true;
        
        bool b_up =false, b_down =false, b_left =false, b_right = false;
        //up
        if(i > 0 && word[index] == board[i][j])
            b_up = dfs(word, index+1, board, i-1, j);
        //down
        if(i+1 < board.size() && word[index] == board[i][j])
            b_down = dfs(word, index+1, board, i+1, j);
            
        //left
        if(j > 0 && word[index] == board[i][j])
            b_left = dfs(word, index+1, board, i, j-1);
        //right
        if(j+1 < board[0].size() && word[index] == board[i][j])
            b_right = dfs(word, index+1, board, i, j+1);
        
        return b_up || b_down || b_left || b_right;
    }
public:
    bool exist(vector<vector<char> >& board, string word) {
        size_t row = board.size(), col = 0;
        if(row)
            col = board[0].size();
            
        bool ret = false;
        for(size_t i = 0; i < row; ++i) {
            for(size_t j = 0; j < col; ++j) {
                ret = bfs(word, 0, board, i, j);
                if(ret) break;
            }
            if(ret) break;
        }
        return ret;
    }
};

int main(void)
{
	vector<vector<char> > mmap;
	int row, col;
	printf("input row and col:");
	scanf("%d %d", &row, &col);
	
	getchar();
	char c;
	for(int i = 0; i < row; ++i) {
		mmap.push_back(vector<char>());
		for(int j = 0; j < col; ++j) {
			scanf("%c", &c);
			mmap[i].push_back(c);
		}
		getchar();
	}

	string word;
	cout << "input a word:";
	cin >> word;
	Solution ss;
	printf("answer is : %d\n", ss.exist(mmap, word));

	return 0;
}

