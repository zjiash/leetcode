/*
 * =====================================================================================
 *
 *       Filename:  020_Valid_Parentheses.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月03日 20时22分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

bool isValid(string s) {
	stack<char> st;
	for(int i = 0; i < s.size(); i++){
		char a = s[i];
		if(a == '(' || a == '{' || a == '[')
		  st.push(a);
		else if(a == ')'){
			if(!st.empty() && st.top() == '(')
			  st.pop();
			else
			  return false;
		}
		else if(a == '}'){
			if(!st.empty() && st.top() == '{')
			  st.pop();
			else
			  return false;
		}
		else if(a == ']'){
			if(!st.empty() && st.top() == '[')
			  st.pop();
			else
			  return false;
		}
	}

	return st.empty();
}

