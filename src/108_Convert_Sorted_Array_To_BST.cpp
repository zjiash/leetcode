/*
 * =====================================================================================
 *
 *       Filename:  108_Convert_Sorted_Array_To_BST.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 14时44分49秒
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
	TreeNode *solve(vector<int> &num, int start, int end){
		TreeNode *root = NULL;
		if(end < start)
		  return root;
		int mid = start + (end - start) / 2;
		int val = num[mid];
		root = new TreeNode(val);
		root->left = solve(num, start, mid-1);
		root->right = solve(num, mid+1, end);
		return root;
	}

	TreeNode *sortedArrayToBST(vector<int> &num) {
		return solve(num, 0, num.size()-1);
	}
};
