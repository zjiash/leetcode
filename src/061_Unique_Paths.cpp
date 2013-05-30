/*
 * =====================================================================================
 *
 *       Filename:  061_Unique_Paths.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月11日 23时05分58秒
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
	int uniquePaths(int m, int n) {
		/*
		if(m == 1 || n == 1)
		  return 1;
		return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
		*/
		int a[101][101];
		for(int i = 0; i <= n; i++)
		  a[1][i] = 1;
		for(int i = 0; i <= m; i++)
		  a[i][1] = 1;
		for(int i = 2; i <= m; i++){
			for(int j = 2; j <= n; j++){
				a[i][j] = a[i-1][j] + a[i][j-1];
			}
		}
		return a[m][n];
	}
};
