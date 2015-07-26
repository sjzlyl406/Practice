/*************************************************************************
	> File Name: test105.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月24日 星期五 23时25分31秒
 ************************************************************************/

/************************************************************************
 * Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * For example,
 *
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * Return
 *   [
 *       ["hit","hot","dot","dog","cog"],
 *           ["hit","hot","lot","log","cog"]
 *             ]
 *             Note:
 *             All words have the same length.
 *             All words contain only lowercase alphabetic characters.
 *             ]
 *      ]
 *  ]
 * *******************************************************************/
#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;


class Solution {
    vector<vector<string> > result;
    vector<string> path;
   
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    	size_t len = start.size();
        deque<string> cur_deq, tmp_deq;
        cur_deq.push_back(start);
        bool flag = true;   //没有结束
        
 /*       if(dict.find(start) != dict.end()) {
            dict.erase(dict.find(start));
        } */
        unordered_map<string, string> mmap;

        while(flag && !cur_deq.empty()) {
            while(!cur_deq.empty()) {
                string cur_str = cur_deq.front();
                cur_deq.pop_front();
                string next_str = cur_str;  //记录下一个结
                
                for(size_t i = 0; i < cur_str.size(); ++i) {
                    for(char m = 'a'; m <= 'z'; ++m) {
                        if(cur_str[i] != m) {   //排除自身
                            swap(cur_str[i], m);
                            if(cur_str == end) { //结束判断
                                mmap[cur_str]=next_str;
                                getPath(mmap, start, cur_str);
                                result.push_back(path);
        
                                flag = false;   //标志结束
                            }
                            if(dict.find(cur_str) != dict.end()) {
								printf("%s\n", cur_str.c_str());
                                tmp_deq.push_back(cur_str);
                                dict.erase(dict.find(cur_str));
                                
                                mmap[cur_str]=next_str;
                            }
                            swap(cur_str[i], m);
                        }
                    }
                }
            }
            swap(cur_deq, tmp_deq);
            tmp_deq.clear();
        }
        return result;
    }
    
private:
    void getPath(unordered_map<string,string> &mmap,const string &start, const string &str) {
        string p = str;
        path.clear();
        while(p != start) {
            path.push_back(p);
			p = mmap[p];
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
    }
};

int main(void)
{
	string str[8] = {"ted", "tex", "red", "tax", "tad", "den", 
		"rex", "pee"};
	unordered_set<string> dict;
	for(size_t i = 0; i < 8; ++i) {
		dict.insert(str[i]);
	}
	Solution dd;
	vector<vector<string> > vec = dd.findLadders("red", "tax", dict);
	for(size_t i = 0; i < vec.size(); ++i) {
		for(size_t j = 0; j < vec[0].size(); ++j) {
			printf("%s\t", vec[i][j].c_str());
		}
		printf("\n");
	}
}
