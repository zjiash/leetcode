/*
 * =====================================================================================
 *
 *       Filename:  078_Subsets.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月14日 18时23分28秒
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
	bool getBit(long long a, int i){
		return a & (1 << i);
	}

	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int> > res;
		sort(S.begin(), S.end());
		long long tag = 0;
		int size = S.size();
		while(tag < (1 << size)){
			vector<int> ans;
			for(int i = 0; i < size; i++){
				if(getBit(tag, i))
				  ans.push_back(S[i]);
			}
			res.push_back(ans);
			tag++;
		}
		return res;
	}
};
