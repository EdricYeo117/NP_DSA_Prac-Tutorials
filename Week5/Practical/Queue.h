// Queue.h - Specification of Queue ADT (Pointer-based)
#pragma once
#include <string>
#include <iostream>
using namespace std;

typedef char ItemType;

// Define a templated node structure
template <typename T>
struct Node {
    T item;
    Node* next;
};

// Define a templated Queue class
template <typename T>
class Queue {
private:
    Node<T>* frontNode;
    Node<T>* backNode;

public:
    Queue();  // Constructor
    ~Queue();  // Destructor
    bool enqueue(T item);  // Add item to the queue
    bool dequeue();  // Remove item from the front of the queue
    bool dequeue(T& item);  // Retrieve and remove item from the front of the queue
    void getFront(T& item);  // Retrieve item from the front without removing
    bool isEmpty() const;  // Check if the queue is empty
    void displayItems() const;  // Display all items in the queue
};
