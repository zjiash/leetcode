/*
 * =====================================================================================
 *
 *       Filename:  Median_2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月28日 22时57分46秒
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

int findK(int *A, int m, int* B, int n, int k){
	/*
	cout << "s-------------" << endl;
	for(int i = 0; i < m; i++)
	  cout << *(A+i) << " ";
	cout << endl;

	for(int i = 0; i < n; i++)
	  cout << *(B+i) << " ";
	cout << endl;

	cout << "k=" << k << endl;
	cout << "e-------------" << endl;
*/
	if(m <= 0)
	  return *(B+k-1);
	else if(n <= 0)
	  return *(A+k-1);

	int amid = (m-1) >> 1;
	int bmid = (n-1) >> 1;
	int len = amid + bmid + 2;
	if(len > k){
		if(A[amid] < B[bmid])
		  return findK(A, m, B, bmid, k);
		else 
		  return findK(A, amid, B, n, k);
	} else{
		if(A[amid] < B[bmid])
		  return findK(A+amid+1, m-amid-1, B, n, k-amid-1);
		else 
		  return findK(A, m, B+bmid+1, n-bmid-1,  k-bmid-1);
	}
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	double result = 0;
	int sum = m + n;
	if(sum % 2 == 1){
	  result = findK(A, m, B, n, sum/2 + 1);
	}
	else {
	  result = findK(A, m, B, n, sum/2) + findK(A, m, B, n, sum/2+1);
	  result /= 2;
	}
	return result;
}

int main(){
	int a[4] = {2, 2, 2, 2};
	int b[3] = {2, 2, 2};
	for(int i = 1; i <= 7; i++){
		cout << i << " " << findK(a, 4, b, 3, i) << endl;
	}

	cout << "**************" << endl;
	int c[5] = {1, 2, 3, 4, 5};
	int d[5] = {6, 7, 8, 9, 10};
	for(int i = 1; i <= 10; i++){
		cout << i << " " << findK(c, 5, d, 5, i) << endl;
	}
}
