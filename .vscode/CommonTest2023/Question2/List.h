#pragma once
const int MAX_SIZE = 50;
typedef int ItemType;
class List
{
private:
    struct Node {
        int item;
        Node* next;
    };
    Node* firstNode;
    int size;

public:
    //constructor
    List();

    List(int array[], int aSize);

    int removeFirst();
    
    // duplicate another copy of list and return the new list in "new_list"
    void duplicateList(List& new_list);

    // check and return the size of the list
    int getLength();

    // replace the item at the specified index in the list
    // 1 <= index <= size
    // prints all the items in the list
    void display();

};

#include "List.cpp"