/*
 * =====================================================================================
 *
 *       Filename:  092_Reverse_Linked_List.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 16时58分17秒
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
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if(m == n)
		  return head;
		ListNode *cur = head, *prepre = NULL, *pre = NULL, *next = NULL, *tmp = NULL;
		int cnt = 0;
		while(cur && (++cnt) < m){
			prepre = cur;
			cur = cur->next;
		}
		pre = cur;
		next = cur->next;
		while((++cnt) <= n){
			tmp = next->next;
			next->next = pre;
			pre = next;
			next = tmp;
		}
		cur->next = next;
		if(prepre == NULL)
		  return pre;
		prepre->next = pre;
		return head;
	}
};
