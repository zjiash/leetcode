/*
 * =====================================================================================
 *
 *       Filename:  045_Permutations.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 13时32分56秒
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

	void search(vector<int> &num, int start){
		int size = num.size();
		if(start == size)
		  res.push_back(num);
		else{
			for(int i = start; i < size; i++){
				swap(num, start, i);
				search(num, start + 1);
				swap(num, start, i);
			}
		}
	}

	vector<vector<int> > permute(vector<int> &num) {
		res.clear();
		search(num, 0);
		return res;
	}
};
