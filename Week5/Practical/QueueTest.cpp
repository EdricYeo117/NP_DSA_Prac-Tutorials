#include <iostream>
#include "Queue.h"  
#include "Queue.cpp" 

using namespace std;

int main() {
    Queue q;

    // Test if the queue is initially empty
    cout << "Initial state: " << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;

    // Test enqueue operations
    cout << "Enqueuing elements: A, B, C, D" << endl;
    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');
    q.enqueue('D');
    
    // Display items in the queue
    cout << "Queue after enqueues: ";
    q.displayItems();  // Expected output: A B C D

    // Test getFront operation
    char frontItem;
    q.getFront(frontItem);
    cout << "Item at front of the queue: " << frontItem << endl;  // Expected output: A

    // Test dequeue without retrieving the item
    cout << "Dequeueing front item." << endl;
    q.dequeue();
    cout << "Queue after first dequeue: ";
    q.displayItems();  // Expected output: B C D

    // Test dequeue with retrieving the item
    char dequeuedItem;
    if (q.dequeue(dequeuedItem)) {
        cout << "Dequeued item: " << dequeuedItem << endl;  // Expected output: B
    } else {
        cout << "Queue is empty. No item to dequeue." << endl;
    }
    
    // Display items in the queue after dequeuing
    cout << "Queue after second dequeue: ";
    q.displayItems();  // Expected output: C D

    // Enqueue more elements
    cout << "Enqueuing elements: E, F" << endl;
    q.enqueue('E');
    q.enqueue('F');

    // Display items in the queue
    cout << "Queue after additional enqueues: ";
    q.displayItems();  // Expected output: C D E F

    // Dequeue all elements to empty the queue
    cout << "Dequeuing all elements to empty the queue." << endl;
    while (!q.isEmpty()) {
        q.dequeue(dequeuedItem);
        cout << "Dequeued: " << dequeuedItem << endl;
    }

    // Check if queue is empty
    cout << "Final state: " << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;

    return 0;
}
