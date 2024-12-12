// Queue.h Specification of Queue (Pointer-based Implementation)
#pragma once
#include <iostream> 
#include "Stack.h"
using namespace std;

typedef int ItemType;

class Queue
{
private:
	Stack s1;
	Stack s2;

public:
	Queue();
	~Queue();

	// enqueue item at back of the queue
	bool enqueue(ItemType item);

	// dequeue item from front of the queue
	bool dequeue();

	// retrieve item from front of queue
	void getFront(ItemType& item);

	// check if the queue is empty
	bool isEmpty();

};


#include "Queue.cpp"