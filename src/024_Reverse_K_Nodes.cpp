/*
 * =====================================================================================
 *
 *       Filename:  024_Reverse_K_Nodes.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月03日 22时26分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseKGroup(ListNode *head, int k) {
	ListNode *pre = head, *cur = head, *nxt, *tail;
	int a = 0;
	while(cur && (++a < k)){
		cur = cur->next;
	}
	if(k == a){
		tail = pre;
		nxt = cur->next;
		cur = tail->next;
		tail->next = reverseKGroup(nxt, k);
		while(--a){
			nxt = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nxt;
		}
	} 
	return pre;
}

int main(){}
