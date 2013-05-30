/*
 * =====================================================================================
 *
 *       Filename:  Add_Two_4.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月29日 19时13分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

 ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	int tag = 0;
	ListNode *p = l1, *pre = NULL;
	 while(p != NULL && l2 != NULL){
		 p->val += l2->val + tag;
		 if(p->val >= 10){
		   tag = 1;
		   p->val -= 10;
		 } else
		   tag = 0;
		 pre = p;
		 p = p->next;
		 l2 = l2->next;
	 }
	 if(p == NULL){
		 pre->next = l2;
		 p = l2;
	 }
	 while(p != NULL){
		 p->val +=  tag;
		 if(p->val >= 10){
		   tag = 1;
		   p->val -= 10;
		 } else {
			 tag = 0;
			 break;
		 }
		 pre = p;
		 p = p->next;
	 }
	 if(tag)
	   pre->next = new ListNode(1);
	 return l1;
 }
