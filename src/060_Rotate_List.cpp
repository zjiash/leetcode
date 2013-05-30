/*
 * =====================================================================================
 *
 *       Filename:  060_Rotate_List.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月11日 22时40分38秒
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
	ListNode *rotateRight(ListNode *head, int k) {
		ListNode *s1 = head, *s2 = head, *s1p, *s2p, *res;
		if(head == NULL || k == 0)
		  return head;
		int len = 0;
		while(s1){
			s1 = s1->next;
			if(++len == k)
			  break;
		}
		if(s1 == NULL){
			k %= len;
			if(k == 0)
			  return head;
			s1 = head;
			while(k){
				s1 = s1->next;
				k--;
			}
		}
		while(s1){
			s1p = s1;
			s1 = s1->next;
			s2p = s2;
			s2 = s2->next;
		}
		res = s2;
		s2p->next = NULL;
		s1p->next = head;
		return res;
	}
};
