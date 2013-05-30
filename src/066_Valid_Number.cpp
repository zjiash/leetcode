/*
 * =====================================================================================
 *
 *       Filename:  066_Valid_Number.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月12日 00时40分19秒
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
	bool isNumber(const char *s) {
		while(*s == ' '){
			s++;
		}
		bool first = true;
		while(*s){
			if(*s == '+' || *s == '-'){
				if(!first)
				  return false;
				s++;
				if(*s < '0' || *s > '9')
				  return false;
			} else if(*s == 'e'){
				isNumber
			}

		}
	}
};
