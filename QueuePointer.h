// Queue.h - Specification of Queue ADT (implemented using Pointers)
#pragma once
#include<string>
#include<iostream>
using namespace std;

typedef string ItemType;

class Queue
{
  private:
    struct Node
    {
      ItemType item;	// item
      Node     *next;	// pointer pointing to next item
    };

Node *frontNode;	// point to the front node
Node *backNode;     // point to the back node

  public:
	// constructor
	Queue();
    // destructor
    ~Queue();
	// enqueue (add) item at back of the queue
	bool enqueue(ItemType item);

	// dequeue (remove) item from front of the queue
	bool dequeue();

      // retrieve (get) and dequeue item from front of the queue
	bool dequeue(ItemType& item);

	// retrieve (get) item from front of queue
	void getFront(ItemType& item); 

	// check if the queue is empty
	bool isEmpty(); 

      // returns no of elements in queue
	int getNoOfElements(); 
}; 
