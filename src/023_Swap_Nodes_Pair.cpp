/*
 * =====================================================================================
 *
 *       Filename:  023_Swap_Nodes_Pair.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月03日 22时18分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

ListNode *swapPairs(ListNode *head) {
	if(head == NULL || head->next == NULL)
	  return head;
	ListNode *first = head, *second = head->next;
	ListNode *tmp = second->next;
	second->next = first;
	first->next = swapPairs(tmp);
	return second;
}
