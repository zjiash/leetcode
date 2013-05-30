/*
 * =====================================================================================
 *
 *       Filename:  Longest_Substring_3.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月29日 18时16分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstring>
using namespace std;

int tag[26];


int leng(string s, int l, int r){
	if(r == l)
	  return 1;
	int mid = l+(r-l)/2; 
	int lLen = leng(s, l, mid);
	int rLen = leng(s, mid+1, r);
	int len = 0;
	int t[26];
	memset(t, 0, sizeof(t));
	for(int i = mid; i >= 0; i--){
		int index = s[i] - 'a';
		if(t[index] == 0){
			t[index] = 1;
		  len++;
		}
		else break;
	}
	for(int i = mid + 1; i <= r; i++){
		int index = s[i] - 'a';
		if(t[index] == 0){
			t[index] = 1;
		  len++;
		}
		else break;
	}
	int maxLen = lLen;
	if(maxLen < rLen)
	  maxLen = rLen;
	if(maxLen < len)
	  maxLen = len;
	return maxLen;
}

int lengthOfLongestSubstring(string s) {
	if(s.size()==0)
	  return 0;
	return leng(s, 0, s.size()-1);
}

int lengthOfLongestSubstring_1(string s) {
	if(s.size() == 0)
	  return 0;

	memset(tag, -1, sizeof(tag));

	int maxLen = 0;
	int curLen = 0;
	int start = 0, end = 0;
	for(int i = 0; i < s.size(); i++){
		int index = tag[s[i] - 'a'];
		if(index >= 0){
			curLen = end - start;
			maxLen = maxLen < curLen ? curLen : maxLen;
			while(start <= index)
			  tag[s[start++]-'a'] = -1;
			start = index + 1;
		} 
		tag[s[i] - 'a'] = i;
		end++;
	}
	maxLen = maxLen < (end - start) ? (end - start) : maxLen;
	return maxLen;
}

int main(){
	string s = "abcdddah";
	cout << lengthOfLongestSubstring(s) << endl;
}
