/*************************************************************************
	> File Name: test114.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月27日 星期一 19时57分53秒
 ************************************************************************/

/*****************************************************************
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 * *************************************************************/
#include<iostream>

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        if(strs.size() == 0) return vector<string>();
        vector<string> result;
        
        unordered_map<string, vector<string> > mmap;
        for(size_t i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(mmap.find(tmp) != mmap.end()) mmap[tmp].push_back(strs[i]);
            else {
                mmap[tmp]= vector<string>();
                mmap[tmp] .push_back(strs[i]);
            }
        }
        for(auto i = mmap.begin(); i != mmap.end(); ++i) {
            if((i -> second).size() >1) {
                for(size_t j = 0; j < (i->second).size(); ++j) {
                    result.push_back((i->second)[j]);
                }
            }
        }
        return result;
    }
};
