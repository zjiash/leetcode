/*
 * =====================================================================================
 *
 *       Filename:  125_Valid_Palindrome.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月18日 14时15分28秒
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
	int type(char a){
		bool tag1 = a >= '0' && a <= '9'; 
		if(tag1)
		  return 1;
		bool tag2 = a >= 'a' && a <= 'z'; 
		if(tag2)
		  return 2;
		bool tag3 = a >= 'A' && a <= 'Z';
		if(tag3)
		  return 3;
		return 0;
	}

	char format(char a){
		int t = type(a);
		if(t == 3)
		  return a - 'A' + 'a';
		return a;
	}

	bool isPalindrome(string s) {
		int size = s.size();
		int l = 0, r = size - 1;
		while(l < r){
			if(type(s[l]) == 0)
			  ++l;
			else if(type(s[r]) == 0)
			  --r;
			else{
				if(format(s[l]) != format(s[r]))
				  return false;
				++l;
				--r;
			}
		}
		return r <= l;
	}
};
