/*
 * =====================================================================================
 *
 *       Filename:  041_Trapping_Rain_Water.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月09日 17时19分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#define MIN(X, Y) ((X)<(Y))?(X):(Y)
#define MAX(X, Y) ((X)>(Y))?(X):(Y)

class Solution {
public:
	int merge(int A[], int start, int end, int left, int right){
		if(start >= end)
		  return 0;
		int max = A[start];
		int pos = start;
		for(int i = start + 1; i < end; i++){
			if(A[i] > max){
				max = A[i];
				pos = i;
			}
		}
		int lc = merge(A, start, pos, left, MAX(right, max));
		int mc = MAX(MIN(left, right) - A[pos], 0);
		int rc = merge(A, pos + 1, end, MAX(left, max), right);
		return lc + mc + rc;
	}
	int trap(int A[], int n) {
		return merge(A, 0, n, 0, 0);
	}
};
