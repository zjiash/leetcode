/*
 * =====================================================================================
 *
 *       Filename:  043_Wildcard_Matching.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月09日 19时32分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/*
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if(!*s && !*p)
		  return true;
		if(*s && !*p)
		  return false;
		
		if(*p == '?')
		  return *s && isMatch(s + 1, p + 1);
		else if(*p == '*'){
			while(*p == '*')
			  p++;
			bool tag = isMatch(s, p);
			if(tag)
			  return true;
			p--; // *p = '*'	
			if(*(p+1) == '?'){
				if(*s)			 
				  return isMatch(s + 1, p);
			}else if(*s){ // 0 or alpha
				int i = 1;
				while(s[i] && s[i] != *(p+1))
				  i++;
				return isMatch(s + i, p);
			}
		} else if(*s && *p == *s)
		  return isMatch(s + 1, p + 1);
		
		return false;
	}
};
*/

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		int i = 0;
		bool star = false;
		while(s[i]){
			switch(p[i]){
				case '?':
					break;
				case '*':
					star = true;
					s += i;
					p += i;
					while(*p == '*')
					  ++p;
					i = -1;
					break;
				default:
					if(s[i] != p[i]){
						if(star){
							s++;
							i = -1;
						}else
						  return false;
					}
			}
			++i;
		}
		while(p[i] == '*')
		  ++i;
		return p[i] == '\0';
	}
};
