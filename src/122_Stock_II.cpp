/*
 * =====================================================================================
 *
 *       Filename:  122_Stock_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月18日 12时35分31秒
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
		for(int i = 0; i < size - 1; i++){
			profit += prices[i+1] - prices[i] > 0 ? prices[i+1] - prices[i] : 0;
		}
		return profit;
	}
};
