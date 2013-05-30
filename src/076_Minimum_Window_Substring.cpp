/*
 * =====================================================================================
 *
 *       Filename:  076_Minimum_Window_Substring.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月13日 22时42分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
	int count1[256];
	int count2[256];
public:
	string minWindow(string S, string T) {
		string res;
		if(S.size() == 0 || T.size() == 0)
		  return res;

		memset(count1, 0, sizeof(count1));
		memset(count2, 0, sizeof(count2));

		int count = T.size();
		for(int i = 0; i < count; i++){
			count1[T[i]]++;
			count2[T[i]]++;
		}

		int start = 0, end = 0;
		int minSize = S.size() + 1, minStart = 0;
		for(end = 0; end < S.size(); end++){
			if(count2[S[end]] > 0){
				count1[S[end]]--;
				if(count1[S[end]] >= 0)
				  count--;
			}
			if(count == 0){
				while(true){
					if(count2[S[start]] > 0){
						if(count1[S[start]] < 0)
						  count1[S[start]]++;
						else
						  break;
					}
					start++;
				}
				if(minSize > end - start + 1){
					minSize = end - start + 1;
					minStart = start;
				}
			}
		}

		if(minSize == S.size() + 1)
		  return res;
		return string(S, minStart, minSize);
	}
};
