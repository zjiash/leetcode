/*
 * =====================================================================================
 *
 *       Filename:  112_Path_Sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 15时27分18秒
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
public:
	bool solve(TreeNode *root, int sum){
		if(!root)
		  return false;
		sum += root->val;
		if(!root->left && !root->right)
		  return sum == target;
		if(root->left && !root->right)
		  return solve(root->left, sum);
		if(!root->left && root->right)
		  return solve(root->right, sum);
		return solve(root->left, sum) || solve(root->right, sum);

	}
	bool hasPathSum(TreeNode *root, int sum) {
		target = sum;
		return solve(root, 0);
	}
};
