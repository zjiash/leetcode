/*
 * =====================================================================================
 *
 *       Filename:  063_Minimum_Path_Sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月11日 23时50分46秒
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
	int a[201][201];
public:
	int minPathSum(vector<vector<int> > &grid) {
		memset(a, 0, sizeof(a));
		int m = grid.size();
		int n = grid[0].size();
		a[0][0] = grid[0][0];
		for(int i = 1; i < n; i++)
		  a[0][i] = a[0][i-1] + grid[0][i];
		for(int i = 1; i < m; i++)
		  a[i][0] = a[i-1][0] + grid[i][0];
		for(int i = 1; i < m; i++){
			for(int j = 1; j < n; j++){
				a[i][j] = MIN(a[i-1][j], a[i][j-1]) + grid[i][j];
			}
		}
		return a[m-1][n-1];
	}
};
