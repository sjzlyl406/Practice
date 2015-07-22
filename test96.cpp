/*************************************************************************
	> File Name: test96.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月22日 星期三 21时45分25秒
 ************************************************************************/
/************************************************************************
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 * ********************************************************************/
#include<iostream>


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        int index1, index2 ;
        bool flag = true;
        for(size_t i = 0; i < intervals.size(); ++i) {
            if(flag && intervals[i].end >= newInterval.start) {
                flag = false;
                if(newInterval.end < intervals[i].start) {
                    ret.push_back(newInterval);
                    ret.push_back(intervals[i]);
                    continue;
                }
                index1 = min(intervals[i].start, newInterval.start);
                do {
                    i++;
                }while(i < intervals.size() && intervals[i].start <= newInterval.end);
                i--;
                index2 = max(intervals[i].end, newInterval.end);
            }
            else {
                index1 = intervals[i].start;
                index2 = intervals[i].end;
            }
            ret.push_back(Interval(index1, index2));
        }
        if(flag)
            ret.push_back(newInterval);
        return ret;
    }
};
