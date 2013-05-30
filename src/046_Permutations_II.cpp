/*
 * =====================================================================================
 *
 *       Filename:  046_Permutations_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 13时41分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
	vector<vector<int> > res;
public:
	void swap(vector<int> &num, int i, int j){
		int tmp = num[i];
		num[i] = num[j];
		num[j] = tmp;
	}

	vector<vector<int> > permuteUnique(vector<int> &num) {
		res.clear();
		int size = num.size();
		if(size == 0)
		  return res;
		sort(num.begin(), num.end());
		while(true){
			res.push_back(num);
			int i = size - 1, j = i;
			while(i > 0 && num[i] <= num[i-1])
			  i--;
			if(i == 0)
			  break;
			while(num[j] <= num[i-1])
			  j--;
			swap(num, i-1, j);
			reverse(num.begin() + i, num.end());
		}
		return res;
	}
};
