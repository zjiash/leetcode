/*
 * =====================================================================================
 *
 *       Filename:  051_N_Queens_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 16时31分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution { 
	int col;
	int left;
	int right;
	int count;
public:
	void search(int start, int n){
		if(start == n){
			count++;
			return;
		}

		for(int i = 0; i < n; i++){
			if((col & (1 << i)) == 0 && (right & (1 << start + i)) == 0 && (left & (1 << (start - i + n - 1))) == 0){
				col |= 1 << i;
				right |= 1 << start + i;
				left |= 1 << (start - i + n - 1);
				search(start + 1, n);
				col &= ~(1 << i);
				right &= ~(1 << start + i);
				left &= ~(1 << start - i + n - 1);
			}
		}
	}

	int totalNQueens(int n){
		left = right = col = count = 0;
		search(0, n);
		return count;
	}
};
