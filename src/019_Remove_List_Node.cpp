/*
 * =====================================================================================
 *
 *       Filename:  019_Remove_Linked_Node.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月03日 16时33分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

ListNode *removeNthFromEnd(ListNode *head, int n) {
	ListNode *tmp1 = head;
	ListNode *tmp2 = head;
	ListNode *prev = head;
	while(n--)
	  tmp2 = tmp2->next;
	while(tmp2){
		tmp2 = tmp2->next;
		prev = tmp1;
	    tmp1 = tmp1->next;
	}
	if(prev == tmp1){
		head = head->next;
	} else {
		prev->next = tmp1->next;
	}
	delete tmp1;
	return head;
}
