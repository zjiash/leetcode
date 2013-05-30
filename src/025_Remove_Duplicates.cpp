/*
 * =====================================================================================
 *
 *       Filename:  025_Remove_Duplicates.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月03日 23时20分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

int removeDuplicates(int A[], int n) {
	if(n == 0)
	  return 0;
	int index = 0;
	for(int i = 1; i < n; i++){
		if(A[i] != A[index]){
			A[++index] = A[i];
		}
	}
	return index+1;
}
