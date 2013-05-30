/*
 * =====================================================================================
 *
 *       Filename:  036_Sudoku_Solver.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月06日 15时19分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/*
#include <vector>
#include <cstring>
using namespace std;

int getOneBits(int a){
	int res = 0;
	while(a){
		res++;
		a &= a-1;
	}
	return res;
}


bool search(int row[], int col[], int block[], vector<vector<char> > &board, int left){
	if(left == 0)
	  return true;

	int max = -1;
	int id = 0;
	int tmp, bits;
	for(int i = 0; i < 3*9; i++){
		if(i < 9){
			bits = getOneBits(row[i]);
			if(bits < 9 && bits > max){
				max = bits;
				id = i;
			}
		} else if(i < 9*2){
			bits = getOneBits(col[i-9]);
			if(bits < 9 && bits > max){
				max = bits;
				id = i;
			}
		} else {
			bits = getOneBits(block[i-9*2]);
			if(bits < 9 && bits > max){
				max = bits;
				id = i;
			}
		}
	}

	bool tag = false;
	if(id < 9){
		for(int i = 0; i < 9; i++){
			if((row[id] & (1 << i)) == 0){
				for(int j = 0;  j < 9; j++){
					if(board[id][j] == '.' && (col[j] & (1 << i)) == 0 && (block[id/3*3+j/3] & (1 << i)) == 0){
						row[id] |= 1 << i;
					    col[j] |= 1 << i;
					    block[id/3*3+j/3] |= 1 << i;
					    board[id][j] = i + '0';
					    tag = search(row, col, block, board, left - 1);
						if(tag)
						  return tag;
						row[id] &= ~(1 << i);
					    col[j] &= ~(1 << i);
					    block[id/3*3+j/3] &= ~(1 << i);
					    board[id][j] = '.';
					}
				}
			}
		}
	} else if (id < 9*2){
		for(int i = 0; i < 9; i++){
			if((col[id - 9] & (1 << i)) == 0){
				for(int j = 0;  j < 9; j++){
					if(board[j][id] == '.' && (row[j] & (1 << i)) == 0 && (block[j/3*3+id/3] & (1 << i)) == 0){
						row[j] |= 1 << i;
					    col[id] |= 1 << i;
					    block[j/3*3+id/3] |= 1 << i;
					    board[j][id] = i + '0';
					    tag = search(row, col, block, board, left - 1);
						if(tag)
						  return tag;
						row[j] &= ~(1 << i);
					    col[id] &= ~(1 << i);
					    block[j/3*3+id/3] &= ~(1 << i);
					    board[j][id] = '.';
					}
				}
			}
		} 
	}else {
		for(int i = 0; i < 9; i++){
			tmp = id - 9 * 2;
			if((block[tmp] & (1 << i)) == 0){
				for(int j = 0;  j < 9; j++){
					int x = tmp/3*3 + j/3;
					int y = (tmp%3)*3 + j%3;
					if(board[x][y] == '.' && (row[x] & (1 << i)) == 0 && (col[y] & (1 << i)) == 0){
						row[x] |= 1 << i;
					    col[y] |= 1 << i;
					    block[tmp] |= 1 << i;
					    board[x][y] = i + '0';
					    tag = search(row, col, block, board, left - 1);
						if(tag)
						  return tag;
						row[x] &= ~(1 << i);
					    col[y] &= ~(1 << i);
					    block[tmp] &= ~(1 << i);
					    board[x][y] = '.';
					}
				}
			}
		}
	}

	return tag;
}
*/

#include <vector>
#include <cstring>
using namespace std;

#define NUM 9

class Solution {
	int row[NUM];
	int col[NUM];
	int block[NUM];
	int left;

public:
	int getMaxProbability(int x, int y){
		int z = x/3*3+y/3;
		int val = row[x] | col[y] | block[z];
		int res = 0;
		while(val){
			res++;
			val &= val - 1; 
		}
		return res;
	}

	bool search(vector<vector<char> > &board){
		if(left == 0)
		  return true;

		int max = -1, x, y;
		for(int i = 0; i < NUM; i++){
			for(int j = 0; j < NUM; j++){
				if(board[i][j] != '.')
				  continue;
				int tmp = getMaxProbability(i, j);
				if(tmp == 9){
					return false; // wrong try
				} else if(tmp > max){
					max = tmp;
					x = i;
					y = j;
				}
			}
		}

		if(max < 0)
		  return false;

		int z = x/3*3+y/3;
		int mask = row[x] | col[y] | block[z];
		for(int i = 1; i <= NUM; i++){
			if((mask & (1 << i)) == 0){
					row[x] |= 1 << i;
					col[y] |= 1 << i;
					block[z] |= 1 << i;
					board[x][y] = i + '0';
					left--;
					if(search(board))
					  return true;
					row[x] &= ~(1 << i);
					col[y] &= ~(1 << i);
					block[z] &= ~(1 << i);
					board[x][y] = '.';
					left++;
			}
		}
		return false;
	}

	void solveSudoku(vector<vector<char> > &board) {
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(block, 0, sizeof(block));
		char cell;
		left = 0;
		for(int i = 0; i < NUM; i++){
			for(int j = 0; j < NUM; j++){
				cell = board[i][j];
				if(cell != '.'){
					int num = cell - '0';
					row[i] |= 1 << num;
					col[j] |= 1 << num;
					block[i/3*3+j/3] |= 1 << num;
				} else
				  left++;
			}
		}

		search(board);
	}
};

int main(){
}

