/*
 * =====================================================================================
 *
 *       Filename:  033_Search_Range.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月06日 13时12分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>
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

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> res(2);
		int index = binarySearch(A, 0, n, target);
		if(index == -1){
			res[0] = -1;
			res[1] = -1;
			return res;
		}

		int l = 0, r = index - 1, mid;
		while(l < r){
			mid = l + (r - l) / 2;
			if(A[mid] == target)
			  r = mid - 1;
			else 
			  l = mid + 1;
		}
		res[0] = (r >= 0 && A[r] == target) ? r : r + 1;
		l = index + 1;
		r = n - 1;
		while(l < r){
			mid = l + (r - l) / 2;
			if(A[mid] == target)
			  l = mid + 1;
			else 
			  r = mid - 1;
		}
		res[1] = (l < n && A[l] == target) ? l : l - 1;

		return res;
	}
};

int main(){
}
