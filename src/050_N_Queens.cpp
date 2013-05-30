/*
 * =====================================================================================
 *
 *       Filename:  050_N_Queues.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 15时09分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public: 
	vector<vector<string> > res;
	int col;
	int left;
	int right;
	void search(vector<string> &ans, int start, int n){
		if(start == n){
			res.push_back(ans);
			return;
		}

		for(int i = 0; i < n; i++){
			if((col & (1 << i)) == 0 && (right & (1 << start + i)) == 0 && (left & (1 << (start - i + n - 1))) == 0){
				col |= 1 << i;
				right |= 1 << start + i;
				left |= 1 << (start - i + n - 1);
				ans[start][i] = 'Q';
				search(ans, start + 1, n);
				col &= ~(1 << i);
				right &= ~(1 << start + i);
				left &= ~(1 << start - i + n - 1);
				ans[start][i] = '.';
			}
		}
	}

	vector<vector<string> > solveNQueens(int n) {
		res.clear();
		vector<string> ans;
		string tmp(n, '.');
		for(int i = 0; i < n; i++){
			ans.push_back(tmp);
		}
		col = right = left = 0;
		search(ans, 0, n);
		return res;
	}
};

int main(){
	Solution s;
	int n; 
	while(true){
		cin >> n;
		if(n == 0)
		  break;
		s.solveNQueens(n);
		for(int i = 0; i < s.res.size(); i++){
		  for(int j = 0; j < n; j++){
			  cout << s.res[i][j] << endl;;
		  }
		  cout << endl; 
		}
		cout << s.res.size() << endl;
	}
}

