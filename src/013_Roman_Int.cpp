/*
 * =====================================================================================
 *
 *       Filename:  013_Roman_Int.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月30日 19时18分06秒
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

int romanToInt(string s) {
	int a[26];
	memset(a, 0, sizeof(a));
	a['I' - 'A'] = 1;
	a['V' - 'A'] = 5;
	a['X' - 'A'] = 10;
	a['L' - 'A'] = 50;
	a['C' - 'A'] = 100;
	a['D' - 'A'] = 500;
	a['M' - 'A'] = 1000;

	int num = 0;
	int len = s.size();
	int cur = 0;
	for(int i = len - 1; i >= 0; i--){
		int id = s[i] - 'A';
		if(a[id] >= cur){
			num += a[id];
			cur = a[id];
		} else {
			num -= a[id];
			cur = a[id];
		}
	}
	return num;
}

int main(){
	string s;
	while(true){
		cin >> s;
		cout << romanToInt(s) << endl;
	}
}
