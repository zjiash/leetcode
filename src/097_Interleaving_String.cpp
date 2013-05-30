/*
 * =====================================================================================
 *
 *       Filename:  097_Interleaving_String.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 21时42分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
	int size1;
	int size2;
	int size3;
	char tag[100][100][200];
public:

	bool solve(const string &s1, int st1, const string &s2, int st2, const string &s3, int st3){
		bool tag1;
		while(st3 < size3){
			if(s1[st1] == s2[st2]){
				if(s1[st1] != s3[st3]){
					tag[st1][st2][st3] = 1;
					return false;
				}
				if(size1 - st1 < size2 - st2){
					if(tag[st1+1][st2][st3+1] == 0)
					  tag[st1+1][st2][st3+1] = solve(s1, st1+1, s2, st2, s3, st3+1) == true ? 2 : 1;
					if(tag[st1+1][st2][st3+1] > 1)
					  return true;
					++st2;
				 } else {
					if(tag[st1][st2+1][st3+1] == 0)
					  tag[st1][st2+1][st3+1] = solve(s1, st1, s2, st2+1, s3, st3+1) == true ? 2 : 1;
					if(tag[st1][st2+1][st3+1] > 1)
					  return true;
					++st1;
				}
				++st3;
			} else if(s1[st1] == s3[st3]){
				++st1;
				++st3;
			} else if(s2[st2] == s3[st3]){
				++st2;
				++st3;
			} else {
				tag[st1][st2][st3] = 1;
				return false;
			}
		}
		tag[st1][st2][st3] = 2;
		return true;
	}

	bool isInterleave(string s1, string s2, string s3) {
		size1 = s1.size();
		size2 = s2.size();
		size3 = s3.size();
		if(size1 + size2 != size3)
		  return false;
		string tmp1 = s1 + s2;
		string tmp2 = s3;
		sort(tmp1.begin(), tmp1.end());
		sort(tmp2.begin(), tmp2.end());
		if(tmp1.compare(tmp2) != 0)
		  return false;

		memset(tag, 0, sizeof(tag));

		s1 += ' ';
		s2 += ' ';
		return solve(s1, 0, s2, 0, s3, 0);
	}
};
