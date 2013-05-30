/*
 * =====================================================================================
 *
 *       Filename:  053_Spiral_Matrix.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 16时52分15秒
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
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> res;
		int direct = 1;
		int x =0, y = 0;
		int m = matrix.size();
		if(m == 0)
		  return res;
		int n = matrix[0].size();
		int total = m * n;
		res.push_back(matrix[x][y]);
		total--;
		while(total){
			switch(direct % 4){
				case 1:
					if(y == n - 1 - direct / 4){
						direct++;
						break;
					}
					res.push_back(matrix[x][++y]);
					total--;
					break;
				case 2:
					if(x == m - 1 - direct / 4){
					    direct++;
						break;
					}
					res.push_back(matrix[++x][y]);
					total--;
					break;
				case 3:
					if(y == direct / 4){
					    direct++;
						break;
					}
					res.push_back(matrix[x][--y]);
					total--;
					break;
				case 0:
					if(x == direct / 4) {
					    direct++;
						break;
					}
					res.push_back(matrix[--x][y]);
					total--;
					break;
			}
		}
		return res;
	}
};
