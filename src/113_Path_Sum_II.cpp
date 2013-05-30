/*
 * =====================================================================================
 *
 *       Filename:  113_Path_Sum_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 15时39分00秒
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
	int target;
	vector<int> ans;
	vector<vector<int> > res;
public:
	void solve(TreeNode *root, int sum){
		if(!root)
		  return;
		sum += root->val;
		ans.push_back(root->val);
		if(!root->left && !root->right && sum == target)
		  res.push_back(ans);
		if(root->left)
		  solve(root->left, sum);
		if(root->right)
		  solve(root->right, sum);
		ans.pop_back();
	}

	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		ans.clear();
		res.clear();
		target = sum;
		solve(root, 0);
		return res;
	}
};
