/*
 * =====================================================================================
 *
 *       Filename:  056_Insert_Interval.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 19时17分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

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
	int cmp(const Interval &interval, int target){
		return target - interval.start;
	}

	int search(const vector<Interval> &intervals, int target){
		int l = 0, r = intervals.size() - 1;
		while(l <= r){
			int mid = l + (r - l) / 2;
			int tmp = cmp(intervals[mid], target);
			if(tmp < 0)
			  r = mid - 1;
			else if(tmp > 0)
			  l = mid + 1;
			else 
			  return mid;
		}
		return l;
	}

	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> res;
		int size = intervals.size();
		if(size == 0){
			res.push_back(newInterval);
			return res;
		}
		int l = search(intervals, newInterval.start);
		//int r = search(intervals, newInterval.end);
		intervals.insert(intervals.begin() + l, newInterval);
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
