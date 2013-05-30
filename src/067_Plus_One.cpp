/*
 * =====================================================================================
 *
 *       Filename:  067_Plus_One.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月12日 18时37分37秒
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
	vector<int> plusOne(vector<int> &digits) {
		reverse(digits.begin(), digits.end());
		int symbol = 0;
		for(int i = 0; i < digits.size(); i++){
			digits[i] += (i == 0 ? 1 : 0) + symbol;
			if(digits[i] >= 10){
				digits[i] -= 10;
				symbol = 1;
			} else {
			  symbol = 0;
			  break;
			}
		}
		if(symbol == 1)
		  digits.push_back(1);
		reverse(digits.begin(), digits.end());
		return digits;
	}
};
