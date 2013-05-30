/*
 * =====================================================================================
 *
 *       Filename:  103_Binary_Tree_Zigzag_Level_Order_Traversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 23时41分06秒
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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > res;
		if(!root)
		  return res;
		int i = 0;
		int cnt = 1;
		int level = 0;
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
			if(++i == cnt){
				if(level % 2)
				  reverse(tmp.begin(), tmp.end());
				res.push_back(tmp);
				tmp.clear();
				cnt = a.size();
				level++;
			}
		}

		return res;
	}
};
