/*
 * =====================================================================================
 *
 *       Filename:  040_First_Missing_Positive.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月09日 16时42分04秒
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
	int firstMissingPositive(int A[], int n) {
		for(int i = 0; i < n; i++){
			if(A[i] <= 0 || A[i] > n || A[i] == i+1 || A[i] == A[A[i] - 1])
			  continue;
			int tmp = A[A[i]-1];
			A[A[i]-1] = A[i];
			A[i--] = tmp;
		}
		for(int i = 0; i < n; i++){
			if(A[i] != i + 1){
				return i + 1;
			}
		}
		return n + 1;
	}
};
