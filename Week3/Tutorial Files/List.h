// List.h - Specification of List ADT (implemented using Pointers)
#pragma once
#include <string>
#include <iostream>
using namespace std;

typedef string ItemType;

class List {
  private:
    struct Node {
      ItemType item;   // item stored in the node
      Node *next;      // pointer pointing to the next item
    };
    Node *firstNode;   // points to the first item
    int size;          // number of items in the list

  public:
    // Constructor
    // Creates an empty list with no items.
    List();

    // Destructor
    // Deallocates all nodes in the list to prevent memory leaks.
    ~List();

    // Add an item to the back of the list (append)
    // pre: None
    // post: item is added to the end of the list, increasing the size by 1.
    bool add(ItemType item);

    // Add an item at a specified position in the list (insert)
    // pre: 0 <= index <= size && size < MAX_SIZE
    // post: item is added to the specified position in the list;
    //       items at the back are shifted backwards by 1 position.
    bool add(int index, ItemType item);

    // Remove an item at a specified position in the list
    // pre: 0 <= index < size
    // post: item at the specified position is removed, decreasing the size by 1;
    //       items at the back are shifted forward by 1 position.
    void remove(int index);

    // Get an item at a specified position of the list (retrieve)
    // pre: 0 <= index < size
    // post: returns the item at the specified position in the list without modifying the list.
    ItemType get(int index);

    // Check if the list is empty
    // pre: None
    // post: returns true if the list has no items, false otherwise.
    bool isEmpty();

    // Check the size of the list
    // pre: None
    // post: returns the number of items in the list.
    int getLength();

    // Display all the items in the list
    // pre: None
    // post: prints all items in the list in order from first to last.
    void print();
};
