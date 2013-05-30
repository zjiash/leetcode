/*
 * =====================================================================================
 *
 *       Filename:  047_Rotate_Image.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 14时05分05秒
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
	void rotate(vector<vector<int> > &matrix) {
		int size = matrix.size();
		if(size == 0)
		  return;
		for(int i = 0; i < size / 2; i++){
			for(int j = i; j < size - 1 - i; j++){
				int tmp = matrix[i][j];
				int x = j, y = size - 1 - i;
				while(true){
					int tmp0 = matrix[x][y];
					matrix[x][y] = tmp;
					if(x == i && y == j)
					  break;
					tmp = tmp0;
					tmp0 = x;
					x = y;
					y = size - 1 - tmp0;
				}
			}
		}
	}
};
