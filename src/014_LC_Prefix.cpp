/*
 * =====================================================================================
 *
 *       Filename:  014_LC_Prefix.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月30日 21时17分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string> &strs){
	string res;
	if(strs.size() == 0)
	  return res;

	int size = strs.size();
	int i = 0, j = 1;
	string s = strs[0];
	while(i < s.size()){
		for(j = 1; j < size; j++){
			string s2 = strs[j];
			if(i >= s2.size()  || s2[i] != s[i])
			  break;
		}
		if(j != size)
		  break;
		i++;
	}

	res = s.substr(0, i);
	return res;
}

