#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

/* a positive-integer value stack, with no size limit */
typedef struct Stack
{
	ListNode* stack;
	unsigned int curr_cap; //the amount of elements currently in the stack
} Stack;

int getLast(Stack* s); //this function is used for the pop function

void push(Stack* s, unsigned int element);
int pop(Stack* s); // Return -1 if stack is empty

void initStack(Stack* s);
void cleanStack(Stack* s);

bool isEmpty(Stack* s);
bool isFull(Stack* s); //this is not needed as the stack is 'endless', therefore i didnt script it

#endif // STACK_H
