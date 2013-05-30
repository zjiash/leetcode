/*
 * =====================================================================================
 *
 *       Filename:  115_Distinct_Subsequences.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 19时31分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
	int ssize;
	int tsize;
	int tag[5000][100];
public:
	int solve(string &S, int s1, string &T, int s2){
		if(s2 >= tsize)
		  return 1;
		int cnt = 0;
		for(int i = s1; i < ssize; i++){
			if(S[i] == T[s2] && ssize - i >= tsize - s2){
				if(tag[i+1][s2+1] < 0)
				  tag[i+1][s2+1] = solve(S, i+1, T, s2+1);
				cnt += tag[i+1][s2+1];
			}
		}
		tag[s1][s2] = cnt;
		return cnt;
	}

	int numDistinct(string S, string T) {
		ssize = S.size();
		tsize = T.size();
		memset(tag, -1, sizeof(tag));
		return solve(S, 0, T, 0);
	}
};
