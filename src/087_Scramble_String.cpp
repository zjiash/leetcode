/*
 * =====================================================================================
 *
 *       Filename:  087_Scramble_String.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月15日 21时05分46秒
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
#include <cstring>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		return isValid(0,s1.size()-1,0,s2.size()-1,s1,s2);
	}
	
	bool isValid(int l1,int r1,int l2,int r2,string &s1,string &s2){
		if(r1 - l1 != r2 - l2)
		  return false;
		int key = 1;
		int mark1[26];
		int mark2[26];
		memset(mark1,0,sizeof(mark1));
		memset(mark2,0,sizeof(mark2));
		for(int i = 0; i <= r1 - l1;i++){
			mark1[s1[l1 + i] - 'a']++;
			mark2[s2[l2 + i] - 'a']++;
			if(s1[l1 + i] != s2[l2 + i])
			  key = 0;
		}
		if(key == 1)
			return true;
		if(l1 == r1)
			return false;
		for(int i = 0;i < 26;i++){
			if(mark1[i] != mark2[i])
			  return false;
		}
		for(int i = 0; i <= r1 - l1 -1;i++){
			bool tag1,tag2; 
			tag1 = isValid(l1,l1 + i,r2 - i,r2,s1,s2);
			tag2 = isValid(l1+i+1,r1,l2,r2-i-1,s1,s2);
			if(tag1 && tag2)
			  return true;
			tag1 = isValid(l1,l1 + i,l2,l2 + i,s1,s2);
			tag2 = isValid(l1+i+1,r1,l2+i+1,r2,s1,s2);
			if(tag1 && tag2)
			  return true;            
		}
		return false;
	}
		/*
		bool isScramble(string s1, string s2) {
		if(s1.compare(s2) == 0)
		  return true;
		int size1 = s1.size();
		int size2 = s2.size();
		if(size1 != size2)
		  return false;
		char a = s1[0];
		int i = 0, j = 1;
		for(i = 0; i < size2; i++){
			if(a == s2[i]){
	//			cout << i << " " << a << " " << s2[i] << endl;
				j = i + 1;
				while(j < size2 && s1[j - i] == s2[j])
				  j++;
				break;
			}
		}
		if(i == size2)
		  return false;
	//	cout << j << endl;
		return isScramble(string(s1.begin() + j - i, s1.begin() + j), string(s2.begin(), s2.begin() + i)) 
				&& isScramble(string(s1.begin() + j, s1.end()), string(s2.begin() + j, s2.end()));				
	}
	 */
};

int main(){
	string s1("abc"), s2("cab");
	Solution s;
	cout << s.isScramble(s1, s2) << endl;
}
