/*
 * =====================================================================================
 *
 *       Filename:  Palindromic.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月30日 12时26分28秒
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
#include <string>
using namespace std;

#define MIN(a, b) (a)<(b) ? (a):(b)

string longestPalindrome(string s){
	char *str = new char[2005];
	str[0] = '$';
	str[1] = '#';
	int len = 2;
	for(int i = 0; i < s.size(); i++){
		str[len++] = s[i];
		str[len++] = '#';
	}
	str[len] = '\0';

	int id = 0;
	int mx = 0;
	int p[2005];
	int maxLen = 0;
	int index = 0;
	memset(p, 0, sizeof(p));
	for(int i = 1; i < len; i++){
		if(mx > i){
			p[i] = MIN(p[2*id-i], mx - i);
		} else
		  p[i] = 1;
		for(; str[i-p[i]]==str[i+p[i]]; p[i]++)
		  ;
		if(i + p[i] > mx){
			id = i;
			mx = i + p[i];
		}
		if(p[i] > maxLen){
			maxLen = p[i];
			index = i - p[i] + 1;
			index /= 2;
		}
	}
	string res(s, index, maxLen-1);

	return res;
}

int main(){
	string s;
	while(true){
		cin >> s;
		cout << longestPalindrome(s) << endl;
	}
}
