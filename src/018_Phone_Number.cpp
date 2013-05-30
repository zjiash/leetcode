/*
 * =====================================================================================
 *
 *       Filename:  018_Phone_Number.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月03日 15时54分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <string>
using namespace std;

vector<string> getOne(string d, int start, int end){
	vector<string> res;
	if(start >= end){
		string s;
		res.push_back(s);
		return res;
	}
	int digit = d[start] - '0';
	char begin;
	int num;
	if(digit < 7){
		begin = 'a' + (digit-2) * 3;
		num = 3;
	} else if(digit == 7){
		begin = 'p';
		num = 4;
	} else if(digit == 8){
		begin = 't';
		num = 3;
	} else if(digit == 9){
		begin = 'w';
		num = 4;
	}
	vector<string> m = getOne(d, start+1, end);
	for(int i = 0; i < num; i++){
		for(int j = 0; j < m.size(); j++){
			string tmp(1, (begin + i));
			tmp = tmp + m[j];
			res.push_back(tmp);
		}
	}
	return res;
}

vector<string> letterCombinations(string digits) {
	vector<string> res;
	int size = digits.size();

	res = getOne(digits, 0, size);
	return res;
}

int main(){
}
