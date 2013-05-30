/*
 * =====================================================================================
 *
 *       Filename:  052_Maximum_Subarray.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 16时36分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

class Solution {
public:
	int maxSubArray(int A[], int n) {
		int sum = 0;
		int max = 0x80000000;
		for(int i = 0; i < n; i++){
			sum = MAX(sum + A[i], A[i]);
			max = MAX(sum, max);
		}
		return max;
	}
};
