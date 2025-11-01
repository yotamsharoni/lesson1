#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct ListNode
{
	unsigned int value;
	ListNode* next;
} ListNode;

ListNode* initNode();
void clearNode(ListNode* node);
ListNode* addNode(ListNode* list, unsigned int value);
ListNode* removeNode(ListNode* list);

#endif /* LINKEDLIST_H */
