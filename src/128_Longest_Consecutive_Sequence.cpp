/*
 * =====================================================================================
 *
 *       Filename:  128_Longest_Consecutive_Sequence.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月18日 22时50分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_set<int> a;
		int size = num.size();
		for(int i = 0; i < size; i++)
		  a.insert(num[i]);
		int max = 0;
		for(int i = 0; i < size; i++){
			int tmp = num[i];
			int cnt = 0;
			while(a.count(tmp) > 0){
				a.erase(tmp);
				++cnt;
				--tmp;
			}
			tmp = num[i] + 1;
			while(a.count(tmp) > 0){
				a.erase(tmp);
				++cnt;
				++tmp;
			}
			max = max < cnt ? cnt : max;
		}
		return max;
	}
};
