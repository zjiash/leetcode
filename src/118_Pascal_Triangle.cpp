/*
 * =====================================================================================
 *
 *       Filename:  118_Pascal_Triangle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 20时45分49秒
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
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > res;
		if(numRows <= 0)
		  return res;
		vector<int> tmp(1);
		tmp[0] = 1;
		res.push_back(tmp);
		for(int i = 1; i < numRows; i++){
			vector<int> ans(i+1);
			ans[0] = 1;
			ans[i] = 1;
			for(int j = 1; j < i; j++)
			  ans[j] = res[i-1][j-1] + res[i-1][j];
			res.push_back(ans);
		}
		return res;
	}
};
