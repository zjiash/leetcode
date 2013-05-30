/*
 * =====================================================================================
 *
 *       Filename:  057_Length_Of_Last_Word.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 19时54分06秒
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
	int lengthOfLastWord(const char *s) {
		int res = 0;
		int lastLen = 0;
		int len = 0;
		for(int i = 0; s[i]; i++){
			if(s[i] == ' '){
				if(len != 0)
				  lastLen = len;
				len = 0;
			}else{
				len++;
			}
		}
		if(len != 0)
		  return len;
		return lastLen;
	}
};
