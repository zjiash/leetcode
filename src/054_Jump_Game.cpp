/*
 * =====================================================================================
 *
 *       Filename:  054_Jump_Game.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 18时59分17秒
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
	bool canJump(int A[], int n) {
		int longest = 0;
		for(int i = 0; i <= longest; i++){
			if(longest >= n - 1)
			  return true;
			if(A[i] + i > longest)
				longest = A[i] + i;
		}
		return false;
	}
};
