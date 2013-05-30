/*
 * =====================================================================================
 *
 *       Filename:  096_Unique_Binary_Search_Trees_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 21时20分25秒
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
	vector<TreeNode *> solve(int start, int end){
		vector<TreeNode *> res, l, r;
		if(start > end)
		  res.push_back(NULL);
		for(int i = start; i <= end; i++){
			l = solve(start, i-1);
			r = solve(i+1, end);
			for(int j = 0; j < l.size(); j++){
				for(int k = 0; k < r.size(); k++){
					TreeNode *root = new TreeNode(i);
					root->left = l[j];
					root->right = r[k];
					res.push_back(root);
				}
			}

		}
		return res;
	}

	vector<TreeNode *> generateTrees(int n) {
		return solve(1, n);
	}
};
