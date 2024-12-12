// Stack.h (Pointer-based implementation)
#pragma once
#include <iostream>
using namespace std;

typedef int ItemType;

class Stack
{
private:
	struct Node
	{
		ItemType item;
		Node* next;
	};

	Node* topNode;

public:

	Stack();			// Default constructor

	~Stack();			// Destructor

	//push (add) item on top of the stack
	bool push(ItemType item);

	//pop (remove) item from top of stack
	bool pop();

	//get item at the top of stack (version 1)
	ItemType getTop();

	//get item at the top of stack (version 2)
	void getTop(ItemType& item);

	//check if the stack is empty
	bool isEmpty();

};

#include "Stack.cpp"