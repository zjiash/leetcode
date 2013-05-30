/*
 * =====================================================================================
 *
 *       Filename:  029_Substring_Concatenation_All_Words.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月05日 19时29分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution{
private:
	int count[1000];
	int countSize;
	map<string, int> words;
	vector<int> res;

public:
	vector<int> findSubstring(string S, vector<string> &L) {
		res.clear();
		if(L.size() == 0)
		  return res;

		words.clear();
		countSize = 0;
		// count all words and store in map
		for(int i = 0; i < L.size(); i++){
			if(words.count(L[i]) > 0)
			  count[words[L[i]]]++;
			else{
				words[L[i]] = countSize;
				count[countSize++] = 1;
			}
		}

		int step = L[0].size();
		vector<int> sub;
		for(int i = 0; i < step; i++){
			sub.clear();
			// calculate all subcritps of words in L
			for(int j = i; j + step <= S.size();j += step){
				string s(S, j, step);
				if(words.count(s) > 0)
				  sub.push_back(words[s]);
				else
				  sub.push_back(-1);
			}

			int begin = -1;
			int cur = 0;
			int end = sub.size();
			int meet = L.size();
			while(cur < end){
				if(sub[cur] >= 0){ // this word is in L
					if(count[sub[cur]] > 0){ // counting
						if(begin == -1)
							begin = cur;
					} else { //clear previous effect, not all
						while(begin < cur){
							count[sub[begin]]++;
							meet++;
							if(sub[begin++] == sub[cur])
								break;
						}
					}
					meet--;
					count[sub[cur]]--;
				} else { // clear all previous effect
					meet = L.size();
					if(begin != -1){
						while(begin < cur)
							count[sub[begin++]]++;
						begin = -1;
					}
				}

				cur++;
				if(meet == 0){
					res.push_back(begin*step + i);
					meet++;
					count[sub[begin++]]++;
				}
			}
		
			if(begin != -1){
				while(begin < cur)
					count[sub[begin++]]++;
			}

		}

		return res;
	}
};

int main(){
}
