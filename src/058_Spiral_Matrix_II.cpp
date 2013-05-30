/*
 * =====================================================================================
 *
 *       Filename:  058_Spiral_Matrix_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 20时01分38秒
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
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > res;
		if(n == 0)
		  return res;
		vector<int> tmp(n);
		for(int i = 0; i < n; i++)
		  res.push_back(tmp);
		int count = 1, x = 0, y = 0, direct = 1, total = n * n;
		res[x][y] = count++;
		while(count <= total){
			switch(direct % 4){
				case 1:
					if(y == n - 1 - direct / 4){
						direct++;
						break;
					}
					res[x][++y] = count++;
					break;
				case 2:
					if(x == n - 1 - direct / 4){
						direct++;
						break;
					}
					res[++x][y] = count++;
					break;
				case 3:
					if(y == direct / 4){
						direct++;
						break;
					}
					res[x][--y] = count++;
					break;
				case 0:
					if(x == direct / 4){
						direct++;
						break;
					}
					res[--x][y] = count++;
					break;
			}
		}

		return res;
	}
};
