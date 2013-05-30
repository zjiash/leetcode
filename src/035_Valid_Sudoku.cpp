/*
 * =====================================================================================
 *
 *       Filename:  035_Valid_Sudoku.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月06日 13时47分16秒
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
	bool isValidSudoku(vector<vector<char> > &board) {
		int row[9];
		int col[9];
		int block[9];

		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(block, 0, sizeof(block));

		char tmp;
		int num;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				tmp = board[i][j];
				if(tmp != '.'){
					num = tmp - '0';
					if((row[i] & (1 << num)) > 0)
					  return false;
					row[i] |= 1 << num;
					
					if((col[j] & (1 << num)) > 0)
					  return false;
					col[j] |= 1 << num;

					if((block[i/3*3+j/3] & (1 << num)) > 0)
					  return false;
					block[i/3*3+j/3] |= 1 << num;
				}
			}
		}

		return true;
	}
};
