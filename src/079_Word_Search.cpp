/*
 * =====================================================================================
 *
 *       Filename:  079_Word_Search.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月14日 18时47分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
	int row;
	int col;
	vector<vector<int> > dir;
public:
	bool range(int x, int y){
		return 0 <= x && x < row && 0 <= y && y < col;
	}

	bool solve(vector<vector<char> > &a, string &word, int start, int x, int y){
		if(start == word.size())
		  return true;
		if(start == 0){
			for(int i = 0; i < row; i++){
				for(int j = 0; j < col; j++){
					if(a[i][j] == word[start]){
						a[i][j] = ' ';
						if(solve(a, word, 1, i, j))
						  return true;
						a[i][j] = word[start];
					}
				}
			}
		} else{
			for(int i = 0; i < 4; i++){
				int p = x + dir[i][0];
				int q = y + dir[i][1];
				if(range(p, q) && a[p][q] == word[start]){
					a[p][q] = ' ';
					if(solve(a, word, start + 1, p, q))
					  return true;
					a[p][q] = word[start];
				}
			}
		}
		return false;
	}

	bool exist(vector<vector<char> > &board, string word) {
		row = board.size();
		if(row == 0)
		  return false;
		col = board[0].size();
		dir.clear();
		vector<int> tmp(2);
		tmp[0] = -1;
		tmp[1] = 0;
		dir.push_back(tmp);
		tmp[0] = 1;
		tmp[1] = 0;
		dir.push_back(tmp);
		tmp[0] = 0;
		tmp[1] = -1;
		dir.push_back(tmp);
		tmp[0] = 0;
		tmp[1] = 1;
		dir.push_back(tmp);
		return solve(board, word, 0, -1, -1);
	}
};

int main(){
	string word("a");
	vector<vector<char> > a;
	vector<char> tmp;
	tmp.push_back('a');
	a.push_back(tmp);
	Solution s;
	cout << s.exist(a, word) << endl;
}
