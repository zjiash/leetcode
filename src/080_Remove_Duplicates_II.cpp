/*
 * =====================================================================================
 *
 *       Filename:  080_Remove_Duplicates_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月14日 19时25分38秒
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
	int removeDuplicates(int A[], int n) {
		if(n < 3)
		  return n;
		int index = 2;
		for(int i = 2; i < n; i++){
			if(A[i] != A[index-1] || A[i] != A[index - 2])
			  A[index++] = A[i];
		}
		return index;
	}
};
