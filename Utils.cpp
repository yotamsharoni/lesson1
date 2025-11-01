#include <iostream>
#include "Utils.h"

#define ARR_SIZE 10

/*function simply turns an array backwards, by placing and removing all the values in the stack
input: the array, its length
output: nothing*/
void reverse(int* nums, unsigned int size)
{
	Stack* s = new Stack;
	initStack(s);

	int i = 0;
	for (i = 0; i < size; i++) //placing the values in the stack
	{
		push(s, nums[i]);
		nums[i] = 0; //just for 'cleaning', not really needed
	}

	for (i = 0; i < size; i++) //getting the values back, backwards
	{
		nums[i] = pop(s);
	}

	cleanStack(s);
}

/*function gets an input of 10 numbers and places them in an array,
then flips them and returns them
input: none
output: the flipped array*/
int* reverse10()
{
	int* numbers = new int[ARR_SIZE];
	int i = 0;

	std::cout << "Enter 10 whole numbers";
	for (i = 0; i < ARR_SIZE; i++)
	{
		std::cin >> numbers[i];
	}

	reverse(numbers, ARR_SIZE);

	return numbers;
}