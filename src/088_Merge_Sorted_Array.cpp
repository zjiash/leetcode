/*
 * =====================================================================================
 *
 *       Filename:  088_Merge_Sorted_Array.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 13时05分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		for(int i = m - 1; i >= 0; i--){
			A[n+i] = A[i];
		}
		int a = n, b = 0, i = 0;
		while(a < n + m && b < n){
			if(A[a] <= B[b])
			  A[i++] = A[a++];
			else
			  A[i++] = B[b++];
		}
		while(b < n)
		  A[i++] = B[b++];
	}
};

int main(){
	int A[3] = {1, 2, 3};
	int B[1] = {5};
	Solution s;
	s.merge(A, 3, B, 1);
}
