/*
 * =====================================================================================
 *
 *       Filename:  026_Remove_Elements.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月03日 23时27分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

int removeElement(int A[], int n, int elem) {
	int tail = n;
	for(int i = 0; i < tail; i++){
		if(A[i] == elem){
			A[i--] = A[--tail];
		}
	}
	return tail;
}
