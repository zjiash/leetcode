/*
 * =====================================================================================
 *
 *       Filename:  085_Maximal_Rectangle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月15日 20时28分10秒
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
	int solve(vector<int> &A, int col){
		int h[col+1];
		int l[col+1];
		h[0] = l[0] = 0;
		int top = 0;
		int max = 0;
		for(int i = 0; i <= col; i++){
			int cur_h = i == col ? 0 : A[i];
			int j = i;
			while(h[top] > cur_h){
				int sum = (i - l[top]) * h[top];
				max = sum > max ? sum : max;
				j = l[top--];
			}
			if(cur_h > h[top]){
				h[++top] = cur_h;
				l[top] = j;
			}
		}
		return max;
	}

	int maximalRectangle(vector<vector<char> > &matrix) {
		int row = matrix.size();
		if(row == 0)
		  return 0;
		int col = matrix[0].size();
		if(col == 0)
		  return 0;
		vector<int> line(col, 0);
		int max = 0;
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				line[j] = matrix[i][j] == '0' ? 0 : line[j] + 1;
			}
			int tmp = solve(line, col);
			max = tmp > max ? tmp : max;
		}
		return max;
	}
};
