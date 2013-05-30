/*
 * =====================================================================================
 *
 *       Filename:  101_Symmetric_Tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 23时33分28秒
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
	bool solve(TreeNode *p, TreeNode *q) {
		if(!p && !q)
		  return true;
		if(p && !q)
		  return false;
		if(!p && q)
		  return false;
		if(p->val == q->val){
			return solve(p->left, q->right) && solve(p->right, q->left);
		}
		return false;
	}
	
	bool isSymmetric(TreeNode *root) {
		if(!root)
		  return true;
		return solve(root->left, root->right);
	}
};
