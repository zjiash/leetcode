/*
 * =====================================================================================
 *
 *       Filename:  098_Validate_Binary_Search_Tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 22时53分28秒
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
	bool isValidBST(TreeNode *root) {
		int pre = 1 << 31;
		if(root == NULL)
		  return true;
		vector<TreeNode *> s;
		s.push_back(root);
		while(!s.empty()){
			TreeNode *cur = s.back();
			if(cur->left != NULL){
				s.push_back(cur->left);
				cur->left = NULL;
			} else{
				if(cur->val <= pre)
				  return false;
				pre = cur->val;
				s.pop_back();
				if(cur->right != NULL)
				  s.push_back(cur->right);
			}
		}
		return true;
	}
};
