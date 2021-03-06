/*
 * =====================================================================================
 *
 *       Filename:  107_Binary_Tree_Level_Order_Traversal_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 14时40分11秒
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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > res;
		if(!root)
		  return res;
		int i = 0;
		int cnt = 1;
		vector<int> tmp;
		vector<TreeNode *> a;
		TreeNode * cur;
		a.push_back(root);
		while(i < a.size()){
			cur = a[i];
			tmp.push_back(cur->val);
			if(cur->left)
			  a.push_back(cur->left);
			if(cur->right) 
			  a.push_back(cur->right);
			i++;
			if(i == cnt){
				res.push_back(tmp);
				tmp.clear();
				cnt = a.size();
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
