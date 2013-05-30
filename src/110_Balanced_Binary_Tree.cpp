/*
 * =====================================================================================
 *
 *       Filename:  110_Balanced_Binary_Tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 15时13分19秒
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
	int height(TreeNode *root){
		if(root == NULL)
		  return 0;
		int l = height(root->left);
		int r = height(root->right);
		if(l < 0 || r < 0)
		  return -1;
		if(abs(l-r) > 1)
		  return -1;
		return (l > r ? l : r) + 1;
	}
	bool isBalanced(TreeNode *root) {
		return height(root) >= 0;
	}
};
