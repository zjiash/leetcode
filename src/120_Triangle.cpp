/*
 * =====================================================================================
 *
 *       Filename:  120_Triangle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 21时00分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#define MIN(A, B) ((A)<(B)?(A):(B))
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int row = triangle.size();
		vector<int> ans(row), tmp(row);
		ans = triangle[row-1];
		for(int i = row - 2; i >= 0; i--){
			for(int j = 0; j <= i; j++)
			  tmp[j] = MIN(ans[j], ans[j+1]) + triangle[i][j];
			ans = tmp;
		}
		return ans[0];
	}
};
