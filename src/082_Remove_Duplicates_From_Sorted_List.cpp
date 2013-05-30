/*
 * =====================================================================================
 *
 *       Filename:  082_Remove_Duplicates_From_Sorted_List.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月15日 14时21分47秒
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
		ListNode *tmp = head, *pre = NULL;
		while(tmp){
			if(pre == NULL){
				pre = tmp;
				tmp = tmp->next;
				continue;
			}
			if(tmp->val == pre->val){
				tmp = tmp->next;
				pre->next = tmp;
			} else {
				pre = tmp;
				tmp = tmp -> next;
			}
		}
		return head;
	}
};
