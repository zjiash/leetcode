/*
 * =====================================================================================
 *
 *       Filename:  077_Combinations.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月14日 18时14分57秒
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
	int NN;
public:
	void solve(int n, int k, vector<int> &ans){
		if(k == 0){
			res.push_back(ans);
			return;
		}
		if(n <= 0 || n < k)
		  return;
		ans.push_back(NN - n);
		solve(n - 1, k - 1, ans);
		ans.pop_back();
		solve(n - 1, k, ans);
	}

	vector<vector<int> > combine(int n, int k) {
		res.clear();
		NN = n + 1;
		vector<int> ans;
		solve(n, k, ans);
		return res;
	}
};
