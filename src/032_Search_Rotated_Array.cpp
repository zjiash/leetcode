/*
 * =====================================================================================
 *
 *       Filename:  032_Search_Rotated_Array.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月06日 12时11分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int A[], int start, int end, int target){
	int l = start, r = end - 1;
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(A[mid] > target)
		  r = mid - 1;
		else if(A[mid] < target)
		  l = mid + 1;
		else 
		  return mid;
	}
	return -1;
}

class Solution{
public:
	int search(int A[], int n, int target) {
		int l = 0, r = n - 1, mid;
		int pivot = n - 1;
		while(l <= r){
			mid = l + (r - l) / 2;
			if(A[mid] >= A[0] && A[mid] >= A[n - 1]){
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		pivot = l;
		
		int index = binarySearch(A, 0, pivot, target);
		if(index >= 0)
		  return index;
		index =  binarySearch(A, pivot, n, target);
		if(index >= 0)
		  return index;
		
		return -1;
	}
};

int main(){
	int A[6] = {2, 2, 2, 0, 0, 1};
	Solution s;
	cout << s.search(A, 6, 0) << endl;
}
