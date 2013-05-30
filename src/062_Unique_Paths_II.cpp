/*
 * =====================================================================================
 *
 *       Filename:  062_Unique_Paths_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月11日 23时20分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
	int a[101][101];
public:
	int search(vector<vector<int> > &data, int s, int t, int m, int n) {
		if(data[s][t] == 1){
			a[s][t] = 0;
			return 0;
		}

		if(s == m - 1 && t == n - 1){
			a[s][t] = 1;
			return a[s][t];
		}
		if(s+1 < m && a[s+1][t] == -1)
			  a[s+1][t] = search(data, s+1, t, m, n);
		if(t+1 < n && a[s][t+1] == -1)
			  a[s][t+1] = search(data, s, t+1, m, n);
		a[s][t] = a[s+1][t] + a[s][t+1];
		return a[s][t];
	}

	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		for(int i = 0; i < m; i++)
		  for(int j = 0; j < n; j++)
			a[i][j] = -1;
		for(int i = 0; i < n; i++)
		  a[m][i] = 0;
		for(int i = 0; i < m; i++)
		  a[i][n] = 0;
		return search(obstacleGrid, 0, 0, m, n);
	}
};
