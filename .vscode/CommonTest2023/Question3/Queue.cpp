// Queue.cpp - Implementation of Queue ADT (Pointer-based)
#include "Queue.h"

Queue::Queue()
{
	s1 = Stack(); // always empty, ready for enqueue
	s2 = Stack(); // has items in reverse order, ready for dequeue
}

Queue::~Queue() { }

bool Queue::enqueue(const ItemType item)
{
    s1.push(item); // Push item to s1
    return true;   // Always succeeds
}

bool Queue::dequeue()
{
    if (s2.isEmpty()) {
        if (s1.isEmpty()) {
            return false; // Queue is empty
        }
        // Transfer elements from s1 to s2 to prepare for dequeue
        while (!s1.isEmpty()) {
            s2.push(s1.getTop());
            s1.pop();
        }
    }

    s2.pop(); // Remove the front of the queue
    return true; // Operation successful
}


void Queue::getFront(ItemType& item)
{
    if (s2.isEmpty()) {
        if (s1.isEmpty()) {
            throw runtime_error("Queue is empty. No front element available.");
        }
        // Transfer elements from s1 to s2
        while (!s1.isEmpty()) {
            s2.push(s1.getTop());
            s1.pop();
        }
    }

    item = s2.getTop(); // Retrieve the front element
}


bool Queue::isEmpty() 
{ 
  return s1.isEmpty() && s2.isEmpty();
}
