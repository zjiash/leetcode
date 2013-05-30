/*
 * =====================================================================================
 *
 *       Filename:  114_Flatten_Binary_Tree_To_List.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 15时50分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	void flatten(TreeNode *root) {
		vector<TreeNode *> st, res;
		TreeNode *cur = root;
		while(!st.empty() || cur){
			if(cur){
				st.push_back(cur);
				res.push_back(cur);
				cur = cur->left;
			} else {
				cur = st.back();
				st.pop_back();
				cur = cur->right;
			}
		}
		int size = res.size();
		for(int i = 0; i < size; i++){
			res[i]->left = NULL;
			res[i]->right = (i == size - 1) ? NULL : res[i+1];
		}
	}
};
