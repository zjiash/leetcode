/*
 * =====================================================================================
 *
 *       Filename:  038_Combination_Sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月09日 15时50分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	vector<vector<int> >res;
public:
	void search(vector<int> &data, int s, int target, vector<int> &m){
		if(target == 0){
			vector<int> tmp;
			for(int i = 0; i < m.size(); i++)
			  tmp.push_back(m[i]);
			res.push_back(tmp);
			return;
		}

		for(int i = s; i < data.size(); i++){
			if(data[i] <= target){
				m.push_back(data[i]);
				search(data, i, target - data[i], m);
				m.pop_back();
			}else
			  return;
		}
	}

	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> m;
		res.clear();
		search(candidates, 0, target, m);
		return res;
	}
};

int main(){
	vector<int> data;
	data.push_back(1);
	int target = 2;
	Solution s;
	vector<vector<int> > res = s.combinationSum(data, target);
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
