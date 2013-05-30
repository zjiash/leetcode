/*
 * =====================================================================================
 *
 *       Filename:  049_Power.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 14时59分23秒
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
	double cal(double x, unsigned int y){
		if(y == 1)
		  return x;
		double res = cal(x, y/2);
		if(y % 2 == 0)
		  return res * res;
		return res * res * x;
	}

	double pow(double x, int n) {
		if(n == 0)
		  return 1;
		if(n < 0){
			return 1/cal(x, -n);
		}
		return cal(x, n);
	}
};
