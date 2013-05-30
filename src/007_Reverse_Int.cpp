/*
 * =====================================================================================
 *
 *       Filename:  007_Reverse_Int.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月30日 14时42分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

int reverse(int x) {
	int symbol = 1;
	if(x < 0){
	  symbol = -1;
	  x = -x;
	}
	int res = 0;
	while(x){
		res = res * 10 + x % 10;
		x /= 10;
	}
	res *= symbol;
	return res;
}
