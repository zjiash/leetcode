/*
 * =====================================================================================
 *
 *       Filename:  100_Same_Tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 23时29分22秒
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
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if(!p && !q)
		  return true;
		if(p && !q)
		  return false;
		if(!p && q)
		  return false;
		if(p->val == q->val){
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		return false;
	}
};
