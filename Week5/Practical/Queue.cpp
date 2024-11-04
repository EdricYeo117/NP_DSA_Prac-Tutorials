#include <string>
#include <iostream>
#include "Queue.h"

using namespace std;
// Constructor
template <typename T>
Queue<T>::Queue() {
    frontNode = nullptr;
    backNode = nullptr;
}

// Destructor
template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Enqueue (add) item at the back of the queue
template <typename T>
bool Queue<T>::enqueue(T item) {
    Node<T>* newNode = new Node<T>;
    if (newNode == nullptr) {
        return false;  // Memory allocation failed
    }

    newNode->item = item;
    newNode->next = nullptr;

    if (isEmpty()) {
        frontNode = newNode;
        backNode = newNode;
    } else {
        backNode->next = newNode;
        backNode = newNode;
    }
    return true;
}

// Dequeue (remove) item from the front of the queue
template <typename T>
bool Queue<T>::dequeue() {
    if (isEmpty()) {
        return false; // Queue is empty, nothing to dequeue
    }

    Node<T>* temp = frontNode;
    frontNode = frontNode->next;

    if (frontNode == nullptr) {
        backNode = nullptr;
    }

    delete temp;
    return true;
}

// Dequeue (retrieve and remove) item from the front of the queue
template <typename T>
bool Queue<T>::dequeue(T& item) {
    if (isEmpty()) {
        return false;  // Queue is empty, nothing to remove
    }

    item = frontNode->item;
    return dequeue();
}

// Get the front item without removing it
template <typename T>
void Queue<T>::getFront(T& item) {
    if (isEmpty()) {
        return;  // Queue is empty, nothing to get
    }
    item = frontNode->item;
}

// Check if the queue is empty
template <typename T>
bool Queue<T>::isEmpty() const {
    return frontNode == nullptr;
}

// Display all items in the queue
template <typename T>
void Queue<T>::displayItems() const {
    Node<T>* temp = frontNode;
    while (temp != nullptr) {
        cout << temp->item << " ";
        temp = temp->next;
    }
    cout << endl;
}
