/*
 * =====================================================================================
 *
 *       Filename:  081_Search_Rotated_Array_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月14日 19时32分25秒
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

class Solution {
public:
	bool search(int A[], int n, int target) {
		if(n > 1 && A[0] == A[n -1])
		  return A[0] == target || search(A+1, n-2, target);
		int l = 0, r = n - 1, mid;
		int first = n - 1;
		while(l <= r){
			mid = l + (r - l) / 2;
			if(A[mid] >= A[0] && A[mid] >= A[n - 1]){
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		first = l;
		return binary_search(A, A + first, target) || binary_search(A + first, A + n, target);
	}
};

int main(){
	Solution s;
	int A[6] = {2, 2, 2, 0, 0, 1};
	cout << s.search(A, 6, 0) << endl;
}
