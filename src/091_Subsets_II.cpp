/*
 * =====================================================================================
 *
 *       Filename:  091_Subsets_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 14时28分30秒
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
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		vector<vector<int> > res;
		vector<int> set;
		res.push_back(set);
		sort(S.begin(), S.end());
		int i, j, size, pre, cnt;
		for(i = 0; i < S.size(); i++){
			if(i == 0 || S[i] != S[i-1]){
				size = res.size();
				for(j = 0; j < size; j++){
					vector<int> tmp = res[j];
					tmp.push_back(S[i]);
					res.push_back(tmp);
				}
				pre = S[i];
				cnt = 1;
			} else {
				size = res.size();
				for(j = 0; j < size; j++){
					vector<int> tmp = res[j];
					int ss = tmp.size();
					if(ss >= cnt && tmp[ss-cnt] == S[i]){
						tmp.push_back(S[i]);
						res.push_back(tmp);
					}
				}
				cnt++;
			}
		}
		return res;
	}
};
