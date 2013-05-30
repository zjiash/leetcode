/*
 * =====================================================================================
 *
 *       Filename:  086_Partition_List.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月15日 20时52分43秒
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
	ListNode *partition(ListNode *head, int x) {
		ListNode *less = NULL, *lcur = NULL;
		ListNode *more = NULL, *mcur = NULL;
		while(head){
			if(head->val < x){
				if(lcur == NULL)
				  less = lcur = head;
				else {
					lcur->next = head;
					lcur = head;
				}
			}else{
				if(mcur == NULL)
				  more = mcur = head;
				else{
					mcur->next = head;
					mcur = head;
				}
			}
			head = head->next;
		}

		if(mcur)
		  mcur->next = NULL;
		if(lcur == NULL)
		  return more;
		lcur->next = more;
		return less;
	}
};
