/*
 * =====================================================================================
 *
 *       Filename:  044_Jump_Game_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 12时24分57秒
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
	int jump(int A[], int n) {
		int longest = 0;
		int jump = 0;
		int i = 0;
		int maxpos = 0;
		while(longest < n - 1 && i < n){
			if(i < longest){
				if(A[i] + i > A[maxpos] + maxpos){
					maxpos = i;
				}
			} else {
				longest = A[maxpos] + maxpos;
				maxpos = longest;
				jump++;
			}
			i++;
		}
		return jump;
	}
};
