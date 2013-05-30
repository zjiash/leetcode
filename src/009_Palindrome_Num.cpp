/*
 * =====================================================================================
 *
 *       Filename:  009_Palindrome_Num.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月30日 15时29分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

bool isPalindrome(int x){
	if(x < 0)
	  return false;
	long long rx = 0;
	int y = x;
	while(x){
		rx = rx*10 + x % 10;
		x /= 10;
	}
	return rx == y;
}
