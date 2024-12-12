// Q3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Queue.h"

int main()
{
    Queue q;

    std::cout << "Enqueuing 10, 11, 12...\n";
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);

    ItemType frontItem;
    q.getFront(frontItem);
    std::cout << "Front of the queue: " << frontItem << "\n"; // Expect 10

    std::cout << "Dequeuing twice...\n";
    q.dequeue(); // Removes 10
    q.dequeue(); // Removes 11

    q.getFront(frontItem);
    std::cout << "Front of the queue: " << frontItem << "\n"; // Expect 12

    std::cout << "Enqueuing 13, 14...\n";
    q.enqueue(13);
    q.enqueue(14);

    q.getFront(frontItem);
    std::cout << "Front of the queue: " << frontItem << "\n"; // Expect 12

    std::cout << "Dequeuing...\n";
    q.dequeue(); // Removes 12

    q.getFront(frontItem);
    std::cout << "Front of the queue: " << frontItem << "\n"; // Expect 13

    std::cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}