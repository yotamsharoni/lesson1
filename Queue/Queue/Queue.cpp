#include <iostream>
#include <algorithm> //needed for using 'std:fill'
#include "Queue.h"

/*since we didnt learn yet the conventions of function documentation in c++, i do it like in c.
function simply initializes the queue
input: q, a pointer to the struct Queue variable
output: None*/
void initQueue(Queue* q, unsigned int size)
{
	q->queue = new unsigned int[size];
	std::fill(q->queue, q->queue + size, 0); //sets all the array values to 0
	q->capacity = size;
	q->curr_cap = 0;
	q->first = 0;
	q->last = 0;
}

/*function cleans the Queue from values and de-allocates the array memory
input: q, the Queue
output: None*/
void cleanQueue(Queue* q)
{
	delete[] q->queue; //found that this is the way to free allocated memory in c++
	q->capacity = 0;
	q->first = 0;
	q->last = 0;
}

/*function adds a value to the queue at the end of it
input: the Queue, the new value that should be added
output: None*/
void enqueue(Queue* q, unsigned int newValue)
{
	if (isFull(q))
	{
		std::cout << "Queue is full, cannot add another value\n";
		return;
	}
	std::cout << "Added";
	std::cout << q->last;
	q->queue[q->last] = newValue;
	q->last = (q->last + 1) % q->capacity;
	q->curr_cap++;
}

/*function removes the first value in the queue
input: the Queue pointer
output: the value removed*/
int dequeue(Queue* q)
{
	if (isEmpty(q))
	{
		std::cout << "Queue is empty:";
		return -1;
	}
	unsigned int value = q->queue[q->first];
	q->queue[q->first] = 0;
	q->first = (q->first + 1) % q->capacity;
	q->curr_cap--;
	return value;
}

/*function checks if a queue is empty
input: the queue reference
output: a boolean value showing either its empty or not*/
bool isEmpty(Queue* s)
{
	if (s->curr_cap == 0) //if they are equal, it must mean that there are no values in the queue
	{
		return true;
	}
	return false; //no need for an else of course
}

/*function checks if the queue is full
input: the queue pointer
output: a boolean value showing if its full or not*/
bool isFull(Queue* s)
{
	std::cout << s->curr_cap << s->capacity;
	if (s->curr_cap == s->capacity) //checks if the last index is one before the first
	{
		return true; //if it is, then the queue is full
	}
	return false;
}