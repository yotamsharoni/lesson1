#include <iostream>
#include "Stack.h"

/*function simply returns the last nodes value, was made to help 'pop' function
input: the stack pointer
output: the last node's value or -1 if the stack is empty*/
int getLast(Stack* s)
{
	ListNode* curr = s->stack;
	if (isEmpty(s)) //checking if the stack is empty
	{
		return -1;
	}

	while (curr->next) //getting to the last node
	{
		curr = curr->next;
	}
	return curr->value; //returning the last node's value
}

/*function simply adds a node at the end of the stack with the given value
using the linked list function 'addNode()'
input: the stack pointer, the 'element'/value for the new node*/
void push(Stack* s, unsigned int element)
{
	s->stack = addNode(s->stack, element);
	s->curr_cap++; //keeping track on the stack's size
}

/*function simply removes the last node in the stack and returns its value
input: the stack pointer
output: the last node's value or -1 if the stack is empty*/
int pop(Stack* s)
{
	unsigned int value = getLast(s);
	s->stack = removeNode(s->stack);
	s->curr_cap--; //keeps track on the size
	return value;
}

/*function simply inits the stack with a NULL value and the curr_cap with 0
input: the stack pointer
output: none*/
void initStack(Stack* s)
{
	s->stack = NULL;
	s->curr_cap = 0;
}

/*function deletes all the nodes in the stack from the last to the first
input: the stack pointer
output: none*/
void cleanStack(Stack* s)
{
	ListNode* curr = s->stack;
	while (curr)
	{
		removeNode(curr); //removes the last node in the stack
	}
}

/*function returns a boolean value showing if the stack is empty
input: the stack
output: the value, true or false*/
bool isEmpty(Stack* s)
{
	return s->curr_cap == 0;
}