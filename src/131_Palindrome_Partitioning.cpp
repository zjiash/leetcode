/*
 * =====================================================================================
 *
 *       Filename:  131_Palindrome_Partitioning.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月29日 14时25分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
	vector<vector<string> > res;
	vector<string> ans;
public:
	bool isPalindrome(string str){
		int l = 0, r = str.size() - 1;
		while(l < r && str[l] == str[r])
		  ++l, --r;
		return l >= r;
	}

	void solve(string &s, int start, int size){
		if(start == size){
			res.push_back(ans);
			return;
		}

		for(int i = start; i < size; i++){
			string str(s, start, i - start + 1);
			if(isPalindrome(str)){
				ans.push_back(str);
				solve(s, i+1, size);
				ans.pop_back();
			}
		}
	}

	vector<vector<string> > partition(string s) {
		res.clear();
		ans.clear();
		int size = s.size();
		solve(s, 0, size);
		return res;
	}
};
