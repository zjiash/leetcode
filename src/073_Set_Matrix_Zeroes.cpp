/*
 * =====================================================================================
 *
 *       Filename:  073_Set_Matrix_Zeroes.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月13日 14时29分31秒
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
	void setRow(vector<vector<int> > &m, int line, int col){
		for(int i = 0; i < col; i++)
		  m[line][i] = 0;
	}

	void setColumn(vector<vector<int> > &m, int line, int row){
		for(int i = 0; i < row; i++)
		  m[i][line] = 0;
	}

	
	void setZeroes(vector<vector<int> > &matrix) {
		int row = matrix.size();
		if(row == 0)
		  return;

		int col = matrix[0].size();
		bool first = false;
		for(int i = 0; i < col; i++){
			if(matrix[0][i] == 0){
				first = true;
				break;
			}
		}

		for(int i = 1; i < row; i++){
			bool zero = false;
			for(int j = 0; j < col; j++){
				if(matrix[i][j] == 0){
					zero = true;
					matrix[0][j] = 0;
				}
			}
			if(zero)
			  setRow(matrix, i, col);
		}

		for(int i = 0; i < col; i++){
			if(matrix[0][i] == 0)
			  setColumn(matrix, i, row);
		}

		if(first)
		  setRow(matrix, 0, col);
	}
};
