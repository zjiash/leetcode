/*
 * =====================================================================================
 *
 *       Filename:  065_Add_Binary.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月12日 00时23分55秒
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
	string addBinary(string a, string b) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int asize = a.size();
		int bsize = b.size();
		if(asize < bsize){
			string tmp = a;
			a = b;
			b = tmp;
			asize = bsize;
			bsize = b.size();
		}
		int symbol = 0, tmp;
		for(int i = 0; i < asize; i++){
			if(i < bsize){
				tmp = a[i] - '0' + b[i] - '0' + symbol;
			}else{
				tmp = a[i] - '0' + symbol;
			}
			if(tmp >= 2){
				tmp -= 2;
				symbol = 1;
			} else 
			  symbol = 0;
			a[i] = tmp + '0';
			if(i >= bsize && symbol == 0)
			  break;
		}
		if(symbol == 1)
		  a += '1';
		reverse(a.begin(), a.end());
		return a;
	}
};
