/*
 * =====================================================================================
 *
 *       Filename:  075_Sort_Colors.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月13日 22时22分03秒
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
	void swap(int A[], int i, int j){
		int tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}
	void sortColors(int A[], int n) {
		int e0 = 0, e1 = 0, e2 = 0;
		for(int i = 0; i < n; i++){
			if(A[i] == 0){
				if(i != e0)
				  swap(A, i--, e0);
				e0++;
				e1 = e1 < e0 ? e0 : e1;
				e2 = e2 < e1 ? e1 : e2;
			} else if(A[i] == 1) {
				if(i != e1)
				  swap(A, i--, e1);
				e1++;
				e2 = e2 < e1 ? e1 : e2;
			} else {
				if(i != e2)
				  swap(A, i--, e2);
				e2++;
			}
		}
	}
};
