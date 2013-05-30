/*
 * =====================================================================================
 *
 *       Filename:  037_Count_Say.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月09日 15时03分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string inttos(int b){
		string s;
		while(b){
			s = s + (char)(b % 10 + '0');
			b /= 10;
		}
		reverse(s.begin(), s.end());
		return s;
	}

	string countAndSay(int n) {
		string s1, s2;
		s1 = s1 + '1';
		for(int i = 1; i < n; i++){
			s2 = s1;
			s1.clear();
			char cur = s2[0];
			int num = 1;
			for(int j = 1; j < s2.size(); j++){
				if(s2[j] == cur)
				  num++;
				else{
					s1 += inttos(num);
					s1 = s1 + cur;
					cur = s2[j];
					num = 1;
				}
			}
			s1 += inttos(num);
			s1 = s1 + cur;
		}
		return s1;
	}
};

int main(){
	Solution s;
	int n;
	while(true){
		cin >> n;
		if(n <= 0)
		  break;
		cout << s.countAndSay(n) << endl;
	}
}
