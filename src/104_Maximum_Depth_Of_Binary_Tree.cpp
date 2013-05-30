/*
 * =====================================================================================
 *
 *       Filename:  104_Maximum_Depth_Of_Binary_Tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 00时11分47秒
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
	int maxDepth(TreeNode *root) {
		if(root == NULL)
		  return 0;
		int l = maxDepth(root->left);
		int r = maxDepth(root->right);
		return (l > r ? l : r) + 1;
	}
};
