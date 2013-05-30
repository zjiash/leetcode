/*
 * =====================================================================================
 *
 *       Filename:  106_Construct_Binary_Tree_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 14时25分29秒
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
	TreeNode *solve(vector<int> &in, int s1, vector<int> &post, int e1, int len){
		TreeNode *root = NULL;
		if(len <= 0)
		  return root;
		int val = post[e1];
		root = new TreeNode(val);
		int cnt = 0;
		for(int i = s1; i < s1 + len; i++){
			if(in[i] == val)
			  break;
			cnt++;
		}
		root->left = solve(in, s1, post, e1+cnt-len, cnt);
		root->right = solve(in, s1+cnt+1, post, e1-1, len-cnt-1);
		return root;
	}
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int size = inorder.size();
		return solve(inorder, 0, postorder, size-1, size);
	}
};
