#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

/* 
 * create test linked-lists 
 * n = 5  : 1->2->3->4->5->null 
 */
struct ListNode *listCreator(int n)
{
	if (n <= 0) 
		return NULL;
	int i = 2;
	struct ListNode *head, *cur;
	head = cur = (struct ListNode *) malloc(sizeof(struct ListNode));
	cur->val = 1;
	for (i = 2; i <= n; i++) {
		cur->next = (struct ListNode *) malloc(sizeof(struct ListNode));
		cur = cur->next;
		cur->val = i;
	}
	cur->next = NULL;
	return head;
}

/* create test linked-list with cycle 
 * n = 8, m = 3
 * 1->2->3->4->5
 *       |     |
 *       8<-7<-6
 */
struct ListNode *cycleCreator(int n, int m)
{
	if (n <= 0 || m <= 0 || m > n)
		return NULL;
	int i = 2;
	struct ListNode *head, *cur, *cross;
	head = cur = (struct ListNode *) malloc(sizeof(struct ListNode));
	cur->val = 1;
	for (i = 2; i <= n; i++) {
		cur->next = (struct ListNode *) malloc(sizeof(struct ListNode));
		cur = cur->next;
		cur->val = i;
		if (i == m)
			cross = cur;
	}
	cur->next = cross;
	return head;
}

void freeLinkedList(struct ListNode *head)
{
	struct ListNode *node;
	while (head != NULL) {
		node = head;
		head = head->next;
		free(node);
	}	
}

