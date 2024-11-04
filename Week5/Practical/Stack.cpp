#include <string>
#include <iostream>
#include "Stack.h"

using namespace std;
typedef char ItemType;

    Stack::Stack() {
        topNode = nullptr;
    }

    Stack::~Stack() {
        ItemType temp;
        while (!isEmpty()) {
            pop(temp);
        }
    }

	// push item on top of the stack
	bool Stack::push(ItemType item) {
        Node* newNode = new Node;
        // check if memory allocation is successful
        if (newNode == nullptr) {
            return false;
        }
        // assign item to the new node
        newNode->item = item;
        newNode->next = topNode;
        // update topNode to point to the new node
        // this means the newNode is assigned to topNode
        topNode = newNode;
        return true;
    }

	// pop item from top of stack
	bool Stack::pop(){
        if (isEmpty()) {
            return false;
        } else {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
            return true;
        }
    }

      // retrieve and pop item from top of stack
	bool Stack::pop(ItemType &item) {
        if (isEmpty()) {
            return false;
        } else {
            item = topNode->item;
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
            return true;
        }
    }


	// retrieve item from top of stack
	void Stack::getTop(ItemType &item) {
        if (!isEmpty()) {
            item = topNode->item;
        }
    }

	// check if the stack is empty
	bool Stack::isEmpty() {
        return topNode == nullptr;
    }