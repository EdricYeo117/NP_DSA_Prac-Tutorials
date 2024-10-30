#include <string>
#include <iostream>
#include "Queue.h"

using namespace std;
typedef char ItemType;

    // constructor
	Queue::Queue() {
        frontNode = NULL;
        backNode = NULL;
    }
    // destructor
    Queue::~Queue(){
        ItemType temp;
        while (!isEmpty()) {
            dequeue(temp);
        }
    }

	// enqueue (add) item at back of the queue
	bool Queue::enqueue(ItemType item) {
        Node* newNode = new Node;
        newNode->item = item;
        newNode->next = nullptr;
        // if queue is empty
        if (frontNode == NULL) {
            frontNode = newNode;
            backNode = newNode;
        }
        // if queue is not empty
        else {
            backNode->next = newNode;
            backNode = newNode;
        }
        return true;
    }

    // Dequeue (remove) item from front of the queue
    bool Queue::dequeue() {
        if (isEmpty()) {
            return false; // Queue is empty, nothing to dequeue
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;

        if (frontNode == nullptr) {
            // If the queue is now empty, update backNode to nullptr
            backNode = nullptr;
        }

        delete temp;
        return true;
    }

    // retrieve (get) and dequeue item from front of the queue
    bool Queue::dequeue(ItemType& item) {
        Node* temp;

        // if queue is empty
        if (isEmpty()) {
            return false;  // Queue is empty, nothing to remove
        } else {
            // Set temp to point to the front node
            temp = frontNode;

            // Assign the item to the one stored in the front node
            item = temp->item;

            // Adjust the frontNode to point to the next node
            frontNode = frontNode->next;

            // If the queue now becomes empty, set backNode to nullptr as well
            if (frontNode == nullptr) {
                backNode = nullptr;
            }

            // Delete the old front node to free memory
            delete temp;

            return true;  // Dequeue successful
        }
    }

	// retrieve (get) item from front of queue
    void Queue::getFront(ItemType& item) {
        if (isEmpty()) {
            return;
        }
        else {
            item = frontNode->item;
        }
    }

	// check if the queue is empty
	bool Queue::isEmpty() {
        if (frontNode == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

     void Queue::displayItems() {
        Node* temp = frontNode;
        while (temp != nullptr) {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
     }