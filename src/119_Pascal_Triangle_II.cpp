/*
 * =====================================================================================
 *
 *       Filename:  119_Pascal_Triangle_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 20时51分58秒
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
	vector<int> getRow(int rowIndex) {
		int k = rowIndex;
		vector<int> ans(k+1), tmp(k+1);
		ans[0] = 1;
		for(int i = 1; i <= k; i++){
			tmp[0] = 1;
			tmp[i] = 1;
			for(int j = 1; j < i; j++)
			  tmp[j] = ans[j-1] + ans[j];
			ans = tmp;
		}
		return ans;
	}
};
