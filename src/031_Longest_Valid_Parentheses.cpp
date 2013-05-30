/*
 * =====================================================================================
 *
 *       Filename:  031_Longest_Valid_Parentheses.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月05日 21时06分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stack>
#include <string>
using namespace std;

struct Node{
	char c;
	int index;
	Node(){}
	Node(char _c, int idx):c(_c), index(idx){}
};

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<Node> st;
		st.push(Node(')', -1));
		int ret = 0;
		for(int i = 0; i < s.size(); i++){
			char c = s[i];
			if (c == '(')
			  st.push(Node(c, i));
			else{
				Node node = st.top();
				if (node.c == '('){
					st.pop();
					ret = max(ret, i - st.top().index);
				}
				else
				  st.push(Node(c, i));                   
			}
		}
		return ret;
	}
};
