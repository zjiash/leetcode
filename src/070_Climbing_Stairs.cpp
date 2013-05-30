/*
 * =====================================================================================
 *
 *       Filename:  070_Climbing_Stairs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月13日 10时47分13秒
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
	int climbStairs(int n) {
		int a = 0, b = 1;
		for(int i = 0; i < n; i++){
			int pre = b;
			b = a + b;
			a = pre;
		}
		return b;
	}
};
