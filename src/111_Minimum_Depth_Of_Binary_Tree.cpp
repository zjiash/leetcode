/*
 * =====================================================================================
 *
 *       Filename:  111_Minimum_Depth_Of_Binary_Tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 15时22分03秒
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
	int minDepth(TreeNode *root) {
		if(!root)
		  return 0;
		int l = minDepth(root->left);
		int r = minDepth(root->right);
		if(l == 0)
		  return r + 1;
		if(r == 0)
		  return l + 1;
		return (l < r ? l : r) + 1;
	}
};
