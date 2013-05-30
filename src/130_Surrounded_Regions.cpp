/*
 * =====================================================================================
 *
 *       Filename:  130_Surrounded_Regions.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月18日 23时38分52秒
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
	void DFS(vector<vector<char> > &board, int i, int j){
		if(i >= board.size() || j >= board[0].size()) 
		  return;

		if(board[i][j] == 'O'){
			board[i][j] = '#';
			DFS(board, i-1, j);  // to left
			DFS(board, i+1, j);  // to right
			DFS(board, i, j-1);  // to up
			DFS(board, i, j+1);  // to down
		}
	}

	void solve(vector<vector<char>> &board) {
		if(board.empty()) return;

		int len = board[0].size();  // one row length
		
		for(int i = 1; i < len - 1; i++){
			DFS(board, i, 0);        // left
			DFS(board, i, len-1);    // right
		}
		
		for(int j = 0; j < len; j++){
			DFS(board, 0, j);        // up
			DFS(board, len-1, j);    // down
		}
		
		//change 'O' to 'X'
		for(int i = 0; i < len; i++){
			for(int j = 0; j < len; j++){
				if(board[i][j] == 'O') board[i][j] = 'X';
				if(board[i][j] == '#') board[i][j] = 'O';
			}
		}
	}
};
