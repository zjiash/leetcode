/*
 * =====================================================================================
 *
 *       Filename:  006_Zig_Zag.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月30日 14时02分42秒
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
using namespace std;

string convert(string s, int nRows){
	string res(s);
	if(nRows == 1)
	  return res;
	int len = s.size();
	int index = 0;)
	for(int i = 0; i < nRows; i++){
		bool tag = true;
		int j = i;
		while(j < len){
			res[index++]= s[j];
			if(i == nRows-1 || i == 0){
				j += 2*nRows - 2;
			} else if(tag){
			  j += 2*(nRows - i) - 2;
			  tag = false;
			} else {
				j += 2*i;
				tag = true;
			}
		}
	}

	return res;
}

int main(){
	string s;
	int a;
	while(true){
		cin >> s;
		cin >> a;
		cout << convert(s, a) << endl;
	}
}
