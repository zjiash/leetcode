/*
 * =====================================================================================
 *
 *       Filename:  123_Stock_III.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月18日 12时50分37秒
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
		int profit = 0;
		int size = prices.size();
		if(size < 2)
		  return profit;
		int forward[size], backward[size];
		memset(forward, 0, sizeof(forward));
		memset(backward, 0, sizeof(backward));
		int max = prices[size-1];
		for(int i = size - 2; i >= 0; i--){
			if(max < prices[i])
			  max = prices[i];
			else if(max - prices[i] > profit)
			  profit = max - prices[i];
			backward[i] = profit;
		}

		profit = 0;
		int min = prices[0];
		for(int i = 1; i < size; i++){
			if(min > prices[i])
			  min = prices[i];
			else if(prices[i] - min > profit)
			  profit = prices[i] - min;
			forward[i] = profit;
		}

		profit = 0;
		for(int i = 0; i < size; i++){
			int tmp = forward[i] + backward[i];
			profit = profit < tmp ? tmp : profit;
		}

		return profit;
	}
};
