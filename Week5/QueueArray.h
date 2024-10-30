// Queue.h - Specification of Queue ADT (implemented using Circular Array)

#pragma once
#include<string>
#include<iostream>
using namespace std;

const int MAX_SIZE = 100; // Define MAX_SIZE with an appropriate value

typedef int ItemType;

class Queue
{
  private:
    ItemType items[MAX_SIZE];
    int  front;
    int  back;
    bool isFull;
  public:
	// constructor
	Queue();
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
	// check if queue is full
	bool isFull();
}; 
