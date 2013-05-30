/*
 * =====================================================================================
 *
 *       Filename:  132_Palindrome_Partitioning_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月29日 14时50分26秒
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
	int min(int a, int b){
		return a < b ? a : b;
	}

	int minCut(string s) {
		int size = s.size();
		if(size == 0)
		  return 0;
		vector<int> dp(size+1);
		vector<bool> tmp(size, false);
		vector<vector<bool> > book;
		for(int i = 0; i < size; i++){
			dp[i] = size - i - 1;
			book.push_back(tmp);
		}
		dp[size] = -1;

		for(int i = size - 2; i >= 0; i--){
			for(int j = i; j < size; j++){
				if(s[i] == s[j] && ( i+1 >= j-1 || book[i+1][j-1])){
					book[i][j] = true;
					dp[i] = min(dp[i], dp[j+1] + 1);
				}
			}
		}
		return dp[0];
	}
};
