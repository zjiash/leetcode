/*
 * =====================================================================================
 *
 *       Filename:  042_Multiply_Strings.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月09日 18时58分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#define N 1000

class Solution {
public:
	string multiply(string num1, string num2) {
		string s;
		int sum[N];
		memset(sum, 0, sizeof(sum));
		int tmp;
		int aLen = num1.size(), bLen = num2.size();
		for(int i = 0; i < aLen; i++){
			for(int j = 0; j < bLen; j++){
				sum[i+j] += (num1[aLen-1-i] - '0') * (num2[bLen-1-j] - '0');
			}
		}

		for(int i = 0; i < N; i++){
			if(sum[i] >= 10){
				sum[i+1] += sum[i] / 10;
				sum[i] %= 10;
			}
		}
		bool tag = true;
		for(int i = N - 1; i >= 0; i--){
			if(tag && sum[i] == 0)
			  continue;
			else {
				tag = false;
				s += '0' + sum[i];
			}
		}
		if(s.size() == 0)
		  s += '0';
		return s;
	}
};
