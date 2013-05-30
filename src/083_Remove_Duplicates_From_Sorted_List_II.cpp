/*
 * =====================================================================================
 *
 *       Filename:  083_Remove_Duplicates_From_Sorted_List_II.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月15日 14时28分57秒
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

	ListNode *deleteDuplicates(ListNode *head) {
		bool tag = false;
		while(head){
			if(head->next && head->val == head->next->val){
				head = head->next;
				tag = true;
			} else
			  break;
		}
		if(tag && head){
			head = head->next;
			return deleteDuplicates(head);
		}
		if(head == NULL)
		  return head;
		ListNode *pre = head, *mid = head->next, *after;
		int val = pre->val;
		while(mid){
			if(mid->val == val){
				mid = mid->next;
				pre->next = mid;
			} else{
				after = mid->next;
				if(after && after->val == mid->val){
					val = mid->val;
					mid = after->next;
					pre->next = mid;
				} else{
					pre = mid;
					val = pre->val;
					mid = mid->next;
				}
			}
		}
		return head;
	}
};
