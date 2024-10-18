#include <iostream>
#include "Stack.h"
#include "Stack.cpp"

using namespace std;

int main() {
    // (a) Create an empty stack, s
    Stack s;

    // (b) Push '3' on top of the stack
    s.push(3);
    
    // (c) Push '4' on top of the stack
    s.push(4);

    // (d) Get top item of the stack and display
    ItemType topItem;
    s.getTop(topItem); // Get the top item
    cout << "Top item of the stack: " << topItem << endl; // Output: 4

    // (e) Display all the items in the stack in order of insertion
    cout << "Items in the stack in order of insertion: ";
    s.displayInOrderOfInsertion(); // Output: 3 4

    // (f) Pop top item from stack
    s.pop(); // This pops '4'

    // (g) Display all the items in the stack in order of insertion
    cout << "Items in the stack in order of insertion after pop: ";
    s.displayInOrderOfInsertion(); // Output: 3

    return 0;
}
