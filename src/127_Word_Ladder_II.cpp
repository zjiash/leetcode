/*
 * =====================================================================================
 *
 *       Filename:  127_Word_Ladder_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月18日 21时34分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
struct Node{
	string val;
	Node *pre;
	Node(string x) : val(x), pre(NULL){} 
};
class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string> > res;
		vector<Node*> visited;
		int size = start.size();
		Node *cur = new Node(start), *np;
		visited.push_back(cur);
		dict.erase(cur->val);
		int len = 1;
		int tag = 0;
		int shortest = -1;
		for(int i = 0; i < visited.size(); i++){
			cur = visited[i];
			for(int j = 0; j < size; j++){
				for(char k = 'a'; k <= 'z'; k++){
					char tmp = cur->val[j];
					cur->val[j] = k;
					if(cur->val.compare(end) == 0){
						shortest = len + 1;
						cur->val[j] = tmp;
						vector<string> ans;
						ans.push_back(end);
						ans.push_back(cur->val);
						np = cur->pre;
						while(np){
							ans.push_back(np->val);
							np = np->pre;
						}
						reverse(ans.begin(), ans.end());
						res.push_back(ans);
					}else if(dict.count(cur->val) > 0){
						np = new Node(cur->val);
						np->pre = cur;
						visited.push_back(np);
					}
					cur->val[j] = tmp;
				}
			}
			if(i == tag){
				++len;
				for(int j = tag; j < visited.size(); j++)
				  dict.erase(visited[j]->val);
				tag = visited.size() - 1;
			}
			if(len == shortest)
			  break;
		}
		return res;
	}
};
