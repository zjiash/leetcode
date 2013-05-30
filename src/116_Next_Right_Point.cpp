/*
 * =====================================================================================
 *
 *       Filename:  116_Next_Right_Point.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月17日 20时28分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if(!root)
		  return ;
		vector<TreeLinkNode *> res;
		TreeLinkNode *cur = NULL;
		res.push_back(root);
		int pos = 0;
		for(int i = 0; i < res.size(); i++){
			cur = res[i];
			if(cur->left)
			  res.push_back(cur->left);
			if(cur->right)
			  res.push_back(cur->right);
			if(i == pos){
				cur->next = NULL;
				pos = res.size() - 1;
			}
			else
			  cur->next = res[i+1];
		}
	}
};
