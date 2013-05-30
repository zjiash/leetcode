/*
 * =====================================================================================
 *
 *       Filename:  048_Anagrams.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 14时29分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
struct node{
	string val;
	string tag;
};

bool cmp(node n1, node n2){
	return n1.tag.compare(n2.tag) < 0;
}
	

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<string> res;
		int size = strs.size();
		if(size == 0)
		  return res;
		vector<node> data;
		node tmp;
		for(int i = 0; i < size; i++){
			tmp.val = strs[i];
			tmp.tag = strs[i];
			sort(tmp.tag.begin(), tmp.tag.end());
			data.push_back(tmp);
		}
		sort(data.begin(), data.end(), cmp);
		tmp = data[0];
		bool first = true;
		for(int i = 1; i < size; i++){
			if(data[i].tag.compare(tmp.tag) == 0){
				if(first){
					res.push_back(tmp.val);
					first = false;
				}
				res.push_back(data[i].val);
			} else {
				tmp = data[i];
				first = true;
			}
		}

		return res;
	}
};
