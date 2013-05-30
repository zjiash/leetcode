/*
 * =====================================================================================
 *
 *       Filename:  126_Word_Ladder.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月18日 14时27分34秒
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
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		int size = start.size();
		vector<string> bfs;
		bfs.push_back(start);
		int len = 1;
		int tag = 0;
		for(int i = 0; i < bfs.size(); i++){
			string cur = bfs[i];
			for(int j = 0; j < size; j++){
				for(int k = 0; k < 26; k++){
					char tmp = cur[j];
					cur[j] = 'a' + k;
					if(cur.compare(end) == 0)
					  return len + 1;
					if(dict.count(cur) > 0){
						bfs.push_back(cur);
						dict.erase(cur);
					}
					cur[j] = tmp;
				}
			}
			if(i == tag){
				len++;
				tag = bfs.size() - 1;
			}
		}
		return 0;
	}
};
