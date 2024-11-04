#include "List.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Constructor
List::List() {
    firstNode = nullptr;
    size = 0;
}

// Destructor
List::~List() {
    while (!isEmpty())
        remove(0);  
}

// Add an item to the back of the list (append)
bool List::add(ItemType item) {
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;

    if (isEmpty()) {
        firstNode = newNode;
    } else {
        Node* temp = firstNode;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    size++;
    return true;
}

// Add an item at the specified position in the list
bool List::add(int index, ItemType item) {
    if (index < 0 || index > size) {
        return false;
    }

    Node* newNode = new Node;
    newNode->item = item;

    if (index == 0) {
        newNode->next = firstNode;
        firstNode = newNode;
    } else {
        Node* current = firstNode;
        for (int i = 0; i < index - 1; i++) {  
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    size++;
    return true;
}

// Remove an item at a specified position in the list
void List::remove(int index) {
    if (index < 0 || index >= size) {
        return;
    }

    Node* toDelete;
    if (index == 0) {
        toDelete = firstNode;
        firstNode = firstNode->next;
    } else {
        Node* current = firstNode;
        for (int i = 0; i < index - 1; i++) {  
        }
        toDelete = current->next;
        current->next = toDelete->next;
    }
    delete toDelete;
    size--;
}

// Get an item at a specified position of the list
ItemType List::get(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }

    Node* current = firstNode;
    for (int i = 0; i < index; i++) {  
        current = current->next;
    }

    return current->item;
}

// Check if the list is empty
bool List::isEmpty() const {
    return size == 0;
}

// Check the size of the list
int List::getLength() const {
    return size;
}

// Display all the items in the list
void List::print() const {
    Node* current = firstNode;
    while (current != nullptr) {
        cout << current->item << " ";
        current = current->next;
    }
    cout << endl;
}
