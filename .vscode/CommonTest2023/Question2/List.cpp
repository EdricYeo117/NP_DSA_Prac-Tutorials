// List.cpp - Implementation of List ADT using Array
#include <iostream>
#include "List.h"  // header file
using namespace std;

// constructor
List::List() 
{ 
	firstNode = NULL; 
	size = 0;
}

List::List(int arr[], int aSize)
{
	Node* newNode = new Node;  
	newNode->item = arr[0];
	newNode->next = NULL;
	firstNode = newNode; 
	Node* temp = firstNode;
	for (int i = 1; i < aSize; i++)
	{
		Node* newNode = new Node;
		newNode->item = arr[i];
		newNode->next = NULL;
		temp->next = newNode;
		temp = temp->next;
	}
	size = aSize;
}

// int List::removeFirst()
// {       // find and correct the errors
// 	Node* p = firstNode;
// 	Note* ans = p->next;
//         delete p;
// 	return ans->item;
// 	size--;
// }

int List::removeFirst()
{
    if (firstNode == nullptr) {
        // If the list is empty, we cannot remove an item
        throw runtime_error("List is empty. Cannot remove the first item.");
    }

    // Store the item to return
    int removedItem = firstNode->item;

    // Point to the node to be deleted
    Node* nodeToDelete = firstNode;

    // Update the head pointer to the next node
    firstNode = firstNode->next;

    // Free the memory of the removed node
    delete nodeToDelete;

    // Decrement the size of the list
    size--;

    // Return the removed item
    return removedItem;
}


// duplicate another copy of list and return the new list in �new_list�
void List::duplicateList(List& new_list)
{
    if (firstNode == nullptr) {
        // Handle empty list case
        new_list.firstNode = nullptr;
        new_list.size = 0;
        return;
    }

    // Copy the first node
    Node* temp = firstNode;
    Node* newNode = new Node;
    newNode->item = temp->item;
    newNode->next = nullptr;
    new_list.firstNode = newNode;

    // Track the last node of the new list
    Node* temp2 = new_list.firstNode;

    // Iterate through the rest of the nodes
    while (temp->next != nullptr) {
        temp = temp->next;
        Node* newNode = new Node;
        newNode->item = temp->item;
        newNode->next = nullptr;

        temp2->next = newNode; // Link the new node to the new list
        temp2 = temp2->next;   // Advance the pointer in the new list
    }

    // Set the size of the new list
    new_list.size = size;
}

// check the size of the list
int List::getLength() { return size; }

// display the items in the list
void List::display()
{
	Node* temp = firstNode;
	for (int i = 0; i < size; i++)
	{
		cout << temp->item << " ";
		temp = temp->next;
	}
	cout << endl;
	
}
