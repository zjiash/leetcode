/*
 * =====================================================================================
 *
 *       Filename:  068_Text_Justification.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月12日 18时44分13秒
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
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> res;
		int size = words.size();
		int ls = 0, le;
		int count = 0;
		string line;
		for(int i = 0; i < size; i++){
			if(i == 0){
				count = words[i].size();
				le = i;
				continue;
			}

			if(count + 1 + words[i].size() <= L){
				count += 1 + words[i].size();
				le = i;
			} else { 
				int wc = le - ls;
				if(wc == 0){ // just one word
					string tmp(L - count, ' ');
					line = words[ls] + tmp;
				} else {
					int pads = (L - count) / wc;
					int mod = (L - count) % wc;
					line = words[ls];
					for(int j = ls + 1; j <= le; j++){
						int add = 1 + pads + (j - ls <= mod ? 1 : 0);
						string tmp(add, ' ');
						line += tmp + words[j];
					}
				}
				res.push_back(line);
				ls = i;
				count = words[i].size();
				le = i;
			}
		}

		line = words[ls];
		for(int j = ls + 1; j <= le; j++){
			line.push_back(' ');
			line += words[j];
		}
		string tmp(L - count, ' ');
		line += tmp;
		res.push_back(line);

		return res;
	}
};
