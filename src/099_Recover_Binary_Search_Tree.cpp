/*
 * =====================================================================================
 *
 *       Filename:  099_Recover_Binary_Search_Tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 23时06分39秒
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
	TreeNode *first;
	TreeNode *second;
	TreeNode *pre;
public:
	void inorder(TreeNode *cur){
		if(cur == NULL)
		  return;
		inorder(cur->left);
		if(pre && (pre->val > cur->val)){
			if(!first)
			  first = pre;
			second = cur;
		}
		pre = cur;
		inorder(cur->right);
	}

	void recoverTree(TreeNode *root) {
		if(root == NULL)
		  return;
		first = second = pre = NULL;
		inorder(root);
		int tmp = first->val;
		first->val = second->val;
		second->val = tmp;
	}
};
