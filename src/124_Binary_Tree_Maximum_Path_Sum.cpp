/*
 * =====================================================================================
 *
 *       Filename:  124_Binary_Tree_Maximum_Path_Sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月18日 13时54分10秒
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
	int max;
public:
	int getMax(int a, int b, int c){
		int tmp = a > b ? a : b;
		return tmp > c ? tmp : c;
	}

	int solve(TreeNode *root){
		if(!root)
		  return 0;
		int val = root->val;
		int l = solve(root->left);
		int r = solve(root->right);
		int m = l > r ? l : r;
		if(m <= 0)
		  max = max > val ? max : val;
		else
		  max = getMax(max, m + val, l + r + val);

		return getMax(val, val + l, val + r);
	}

	int maxPathSum(TreeNode *root) {
		max = 0x80000000;
		solve(root);
		return max;
	}
};
