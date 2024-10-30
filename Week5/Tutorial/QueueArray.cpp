#include <string>
#include <iostream>
#include "QueueArray.h"

using namespace std;
typedef string ItemType;

// constructor
	Queue::Queue()
    {
        front = 0;
        back = MAX_SIZE - 1;

    }

	// enqueue (add) item at back of the queue
    bool Queue::enqueue(ItemType item) {
        if (isFull()) {
            return false;
        }
        else {
            back = (back + 1) % MAX_SIZE;
            items[back] = item;
            return true;
        }
    }
	// dequeue (remove) item from front of the queue
	bool Queue::dequeue()  {
        if (isEmpty()) {
            return false;
        }
        else {
            front = (front + 1) % MAX_SIZE;
            return true;
        }
    }
      // retrieve (get) and dequeue item from front of the queue
	bool Queue::dequeue(ItemType& item) {
        if (isEmpty()) {
            return false;
        }
        else {
            item = items[front];
            front = (front + 1) % MAX_SIZE;
            return true;
        }
    }
	// retrieve (get) item from front of queue
	void Queue::getFront(ItemType& item) {
        if (isEmpty()) {
            return;
        }
        else {
            item = items[front];
        }
    } 
	// check if the queue is empty
	bool Queue::isEmpty() {
        if (front == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    // check if queue is full
    bool Queue::isFull() {
        if (front == 0 && back == MAX_SIZE - 1) {
            return true;
        }
        else {
            return false;
        }
    }
    