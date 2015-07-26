/*************************************************************************
	> File Name: test104.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月24日 星期五 20时57分38秒
 ************************************************************************/

/*********************************************************************
 * Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * For example,
 *
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 *
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.]
 * ******************************************************************/
#include<iostream>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        size_t len = beginWord.size();
        deque<string> cur_deq, tmp_deq;
        cur_deq.push_back(beginWord);
        int count = 1;
        while(!cur_deq.empty()) {
            count++;    //计数 循环层数 可以改为记录通过路径。
            while(!cur_deq.empty()) {
                string cur_str = cur_deq.front();
                cur_deq.pop_front();
                
                for(size_t i = 0; i < cur_str.size(); ++i) {
                    for(char m = 'a'; m <= 'z'; ++m) {
                        if(cur_str[i] != m) {   //排除自身
                            swap(cur_str[i], m);
                            if(cur_str == endWord)  //结束判断
                                return count;
                            while(wordDict.find(cur_str) != wordDict.end()) {
                                tmp_deq.push_back(cur_str);
                                wordDict.erase(wordDict.find(cur_str));
                            }
                            swap(cur_str[i], m);
                        }
                    }
                }
            }
            swap(cur_deq, tmp_deq);
            tmp_deq.clear();
        }
        return 0;
    }
};
