#include <iostream>
#include "Stack.h"
#include "Stack.cpp"

using namespace std;

int main() {
    Stack s;

    // Test if stack is initially empty
    cout << "Initial state: " << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;

    // Test push operation
    cout << "Pushing elements: A, B, C" << endl;
    s.push('A');
    s.push('B');
    s.push('C');

    // Retrieve the top element
    char topItem;
    s.getTop(topItem);
    cout << "Top element after pushes: " << topItem << endl;  // Expected output: C

    // Pop an element and retrieve it
    char poppedItem;
    if (s.pop(poppedItem)) {
        cout << "Popped element: " << poppedItem << endl;  // Expected output: C
    } else {
        cout << "Failed to pop element. Stack might be empty." << endl;
    }

    // Retrieve the new top element
    s.getTop(topItem);
    cout << "Top element after pop: " << topItem << endl;  // Expected output: B

    // Test if stack is empty
    cout << "Current state: " << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;

    // Pop all elements
    cout << "Popping remaining elements." << endl;
    while (!s.isEmpty()) {
        s.pop(poppedItem);
        cout << "Popped: " << poppedItem << endl;
    }

    // Check if stack is empty
    cout << "Final state: " << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;

    return 0;
}
