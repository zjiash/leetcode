/*
 * =====================================================================================
 *
 *       Filename:  090_Decode_Ways.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 13时37分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
	int cnt[10000];
public:
	int solve(string &s, int start, int end){
		if(start >= end)
		  return 1;
		
		if(s[start] == '0'){
			return 0;
		}

		int num = s[start] - '0';
		if(cnt[start+1] == -1)
		  cnt[start+1] = solve(s, start+1, end);
		int count = cnt[start+1];
		if(start + 1 < end){
			num *= 10;
			num += s[start+1] - '0';
			if(num < 27){
				if(cnt[start+2] == -1)
				  cnt[start+2] = solve(s, start+2, end);
				count += cnt[start+2];
			}
		}
		cnt[start] = count;
		return count;
	}

	int numDecodings(string s) {
		if(s.size() == 0)
		  return 0;
		memset(cnt, -1, sizeof(cnt));
		return solve(s, 0, s.size());
	}
};
