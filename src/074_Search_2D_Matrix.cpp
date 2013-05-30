/*
 * =====================================================================================
 *
 *       Filename:  074_Search_2D_Matrix.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月13日 21时57分47秒
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
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int row = matrix.size();
		int len = row;
		int first = 0, mid;
		while(len > 0){
			int half = len >> 1;
			mid = first;
			mid += half;
			if(matrix[mid][0] < target){
				first = mid;
				++first;
				len = len - half - 1;
			} else if(matrix[mid][0] > target)
			  len = half;
			else
			  return true;
		}

		if(first == 0)
		  return false;
		int line = first - 1;
		return binary_search(matrix[line].begin(), matrix[line].end(), target);
	}
};
