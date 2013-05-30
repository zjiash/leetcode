/*
 * =====================================================================================
 *
 *       Filename:  022_Merge_List.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月03日 21时19分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <vector>
#include <queue>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool operator>(ListNode a, ListNode b){
	return a.val > b.val;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
	priority_queue<ListNode, vector<ListNode>, greater<ListNode> > lqueue;
	ListNode *data;
	for(int i = 0; i < lists.size(); i++){
		data = lists[i];
		if(data != NULL){
			lqueue.push(*data);
		}
	}

	ListNode *head = NULL, *current = NULL,  tmp(0);
	while(!lqueue.empty()){
		tmp = lqueue.top();
		data = new ListNode(tmp.val);
		if(head == NULL)
		  current = head = data;
		else {
		  current->next = data;
		  current = data;
		}
		lqueue.pop();
		
		data = tmp.next;
		if(data != NULL)
		  lqueue.push(*data);
	}

	return head;
}

int main(){
}
