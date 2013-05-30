/*
 * =====================================================================================
 *
 *       Filename:  121_Stock.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月18日 12时27分51秒
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
	int maxProfit(vector<int> &prices) {
		int size = prices.size();
		int profit = 0;
		if(size < 2)
		  return profit;
		int max = prices[size-1];
		for(int i = size - 2; i >= 0; i--){
			if(max < prices[i])
			  max = prices[i];
			else if(max - prices[i] > profit)
			  profit = max - prices[i];
		}
		return profit;
	}
};
