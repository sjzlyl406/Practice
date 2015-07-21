/*************************************************************************
	> File Name: test93.cpp
	> Author: leon
	> Mail: sjzlyl406@163.com 
	> Created Time: 2015年07月22日 星期三 00时27分24秒
 ************************************************************************/

/***********************************************************************
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 * *********************************************************************/
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };


void display(vector<Interval> vec);
bool cmp(const Interval &v1, const Interval &v2)
{
	if(v1.start < v2.start)
		return true;
	else if(v1.start == v2.start)
		return v1.end < v2.end;
	else
		return false;
}
vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> ret;

	bool (*foo)(const Interval &, const Interval &) = cmp;
	sort(intervals.begin(), intervals.end(), *foo);
        
        for(size_t i = 0; i < intervals.size(); ++i) {
            size_t j = i+1;
            int end = intervals[i].end;
            while(j < intervals.size() && intervals[j].start <= end) {
                end = end > intervals[j].end ? end : intervals[j].end;
                j++;
            }
            j--;
            ret.push_back(Interval(intervals[i].start,end));
            i = j;
        }
	display(ret);
	return ret;
}

void display(vector<Interval> vec)
{
	for(size_t i = 0; i < vec.size(); ++i) 
	{
		printf("[%d %d]\t", vec[i].start, vec[i].end);
	}
	printf("\n");
}

int main(void)
{
	vector<Interval> vec;
	vec.push_back({7,7});
	vec.push_back({5,7});
	vec.push_back({1,4});
	vec.push_back({5,6});
	display(vec);
	merge(vec);

	return 0;
}
