#include <iostream>
#include "LinkedList.h"

int main()
{
	ListNode* list = addNode(NULL, 5); //testing if addNode works with null
	std::cout << list->value << "\n";

	addNode(list, 7); //testing if addNode works normally
	std::cout << list->next->value << "\n";

	std::cout << list->next << "\n"; //testing if removeNode works
	removeNode(list);
	std::cout << list->next << "\n";

}

/*function initializes a node
input: none
output: the new node*/
ListNode* initNode()
{
	ListNode* node = new ListNode;
	node->value = 0;
	node->next = NULL;
	return node;
}

/*function clears a node
input: the node requires clearing/deleting
output: none*/
void clearNode(ListNode* node)
{
	delete node;
}

/*function adds a value at the end of the list
input: the list, the value
output: the updated list (needed if the list was originally empty/NULL)*/
ListNode* addNode(ListNode* list, unsigned int value)
{
	ListNode* curr = list;
	if (!curr) //safety check
	{
		curr = initNode();
		curr->value = value;
		return curr;
	}
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = initNode();
	curr = curr->next;
	curr->value = value;
	return list;
}
/*function removes the last node in the list
input: the list
output: the updated list (needed if the list only had one node and is now NULL)*/
ListNode* removeNode(ListNode* list)
{
	ListNode* curr = list;

	if (!curr) //safety check
	{
		return curr;
	}

	if (!list->next) //another safety check
	{
		clearNode(curr);
		curr = NULL;
		return curr;
	}

	while (curr->next->next) //if curr->next->next doesnt exist, it means that curr->next is the last
	{
		curr = curr->next;
	}
	clearNode(curr->next);
	curr->next = NULL;
	return list;
}