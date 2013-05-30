/*
 * =====================================================================================
 *
 *       Filename:  109_Convert_Sorted_List_To_BST.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 14时52分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
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
	TreeNode *solve(ListNode *head, int len){
		TreeNode *root = NULL;
		if(len <= 0)
		  return root;
		ListNode *m = head;
		int mid = len >> 1;
		while(mid--){
			m = m->next;
		}
		root = new TreeNode(m->val);
		root->left = solve(head, len/2);
		root->right = solve(m->next, (len+1)/2-1);
		return root;
	}

	TreeNode *sortedListToBST(ListNode *head) {
		ListNode *tmp = head;
		int len = 0;
		while(tmp){
			++len;
			tmp = tmp->next;
		}
		return solve(head, len);
	}
};
