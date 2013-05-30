/*
 * =====================================================================================
 *
 *       Filename:  089_Gray_Code.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 13时23分59秒
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
	vector<int> grayCode(int n) {
		vector<int> res;
		if(n == 0){
			res.push_back(0);
			return res;
		}

		res = grayCode(n - 1);
		int size = res.size();
		int p = 1 << n - 1;
		for(int i = size - 1; i >= 0; i--){
			res.push_back(res[i] + p);
		}
		return res;
	}
};
