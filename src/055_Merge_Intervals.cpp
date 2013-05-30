/*
 * =====================================================================================
 *
 *       Filename:  055_Merge_Intervals.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 19时05分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

bool cmp(Interval a, Interval b){
	return a.start < b.start;
}

class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> res;
		int size = intervals.size();
		if(size == 0)
		  return res;
		sort(intervals.begin(), intervals.end(), cmp);
		Interval tmp = intervals[0];
		for(int i = 1; i < intervals.size(); i++){
			if(intervals[i].start > tmp.end){
				res.push_back(tmp);
				tmp = intervals[i];
			} else if(intervals[i].end > tmp.end){
				tmp.end = intervals[i].end;
			}
		}
		res.push_back(tmp);
		return res;
	}
};
