/*
 * =====================================================================================
 *
 *       Filename:  094_Binary_Tree_Inorder_Traversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 18时50分12秒
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
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		if(root == NULL)
		  return res;
		vector<TreeNode *> s;
		TreeNode *p = root;
		while(!s.empty() || p){
			if(p != NULL){
				s.push_back(p);
				p = p->left;
			} else{
				p = s.back();
				s.pop_back();
				res.push_back(p->val);
				p = p->right;
			}
		}
		return res;
	}

	vector<int> inorderTraversal_recur(TreeNode *root) {
		vector<int> res, tmp;
		if(root == NULL)
		  return res;
		if(root->left != NULL){
			tmp = inorderTraversal(root->left);
			for(int i = 0; i < tmp.size(); i++)
			  res.push_back(tmp[i]);
		}
		res.push_back(root->val);
		if(root->right != NULL){
			tmp = inorderTraversal(root->right);
			for(int i = 0; i < tmp.size(); i++)
			  res.push_back(tmp[i]);
		}
		return res;
	}
};
