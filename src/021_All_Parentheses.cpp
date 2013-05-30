/*
 * =====================================================================================
 *
 *       Filename:  021_All_Parentheses.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月03日 20时32分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

void DFS(string &s, int l, int r, int n, vector<string> &res){
	if(l+r == 2*n){
		res.push_back(s);
	} else {
		if(l < n){
			s.push_back('(');
			DFS(s, l+1, r, n, res);
			s.pop_back();
		}
		if(l > r){
			s.push_back(')');
			DFS(s, l, r+1, n, res);
			s.pop_back();
		}
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> res;
	string s;
	DFS(s, 0, 0, n, res);
	return res;
}
