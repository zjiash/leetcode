/*
 * =====================================================================================
 *
 *       Filename:  105_Construct_Binary_Tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 14时05分29秒
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
	TreeNode *solve(vector<int> &pre, int s1, vector<int> &in, int s2, int len){
		TreeNode *root = NULL;
		if(len <= 0)
		  return root;
		int val = pre[s1];
		root = new TreeNode(val);
		int cnt = 0;
		for(int i = s2; i < s2 + len; i++){
			if(in[i] == val)
			  break;
			cnt++;
		}
		root->left = solve(pre, s1+1, in, s2, cnt);
		root->right = solve(pre, s1+cnt+1, in, s2+cnt+1, len-cnt-1);
		return root;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		TreeNode *root = NULL;
		int size = preorder.size();
		root = solve(preorder, 0, inorder, 0, size);
		return root;
	}
};
