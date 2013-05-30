/*
 * =====================================================================================
 *
 *       Filename:  034_Search_Insert_Position.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月06日 13时36分46秒
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
	int searchInsert(int A[], int n, int target) {
		int l = 0, r = n - 1;
		while(l <= r){
			int mid = l + (r - l) / 2;
			if(A[mid] > target)
			  r = mid - 1;
			else if(A[mid] < target)
			  l = mid + 1;
			else
			  return mid;
		}

		return l;
	}
};
