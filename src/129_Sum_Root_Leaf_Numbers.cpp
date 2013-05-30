/*
 * =====================================================================================
 *
 *       Filename:  129_Sum_Root_Leaf_Numbers.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月18日 23时29分01秒
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
	int sum;
public:
	void solve(TreeNode *root, int base){
		if(!root)
		  return;
		int cur = base + root->val;
		if(!root->left && !root->right)
		  sum += cur;
		if(root->left)
		  solve(root->left, cur*10);
		if(root->right)
		  solve(root->right, cur*10);
	}
	int sumNumbers(TreeNode *root) {
		sum = 0;
		solve(root, 0);
		return sum;
	}
};
