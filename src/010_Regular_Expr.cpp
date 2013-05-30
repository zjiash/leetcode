/*
 * =====================================================================================
 *
 *       Filename:  010_Regular_Expr.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月30日 15时52分57秒
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

bool isMatch(const char *s, const char *p) {
	if(s[0] == '\0' && p[0] == '\0')
	  return true;
	else if(s[0] != '\0' && p[0] == '\0')
	  return false;
	
	if(p[1] == '*'){
		if((p[0] == '.' && s[0]) || s[0] == p[0])
		  return isMatch(s, p+2) || isMatch(s+1, p);
		else
		  return isMatch(s, p+2);
	} else {
		if((p[0] == '.' && s[0]) || s[0] == p[0])
		  return isMatch(s+1, p+1);
		else return false;
	}
	return false;
}

int main(){
	string a, b;
	while(true){
		cin >> a >> b;
		cout << isMatch(a.c_str(), b.c_str()) << endl;
	}
}
