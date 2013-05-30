/*
 * =====================================================================================
 *
 *       Filename:  095_Unique_Binary_Search_Trees.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 20时56分51秒
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
	int numTrees(int n) {
		long long catalan[n+1];
		catalan[0] = 1;
		for(int i = 1; i <= n; i++){
			catalan[i] = catalan[i-1]*(4*i-2)/(i+1);
		}
		return (int)catalan[n];
	}
};
