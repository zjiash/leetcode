/*
 * =====================================================================================
 *
 *       Filename:  064_Merge_Two_Sorted_lists.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月12日 00时04分33秒
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

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if(!l1)
		  return l2;
		if(!l2)
		  return l1;
		ListNode *head = NULL, *tmp = NULL;
		if(l1->val < l2->val){
			head = l1;
			l1 = l1->next;
		} else {
			head = l2;
			l2 = l2->next;
		}
		tmp = head;
		while(l1 && l2){
			if(l1->val < l2->val){
				tmp->next = l1;
				l1 = l1->next;
			} else {
				tmp->next = l2;
				l2 = l2->next;
			}
			tmp = tmp->next;
		}
		if(l1 == NULL)
		  tmp->next = l2; 
		else
		  tmp->next = l1;
		return head;
	}
};
