// Test1SampleQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Queue.h"
#include "Customer.h"

using namespace std;

void registerCustomer(Queue& serviceQueue, int& queueNumber) {
    string customerName;

    cout << "Enter customer's name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, customerName); // Get the customer's name

    // Create a new customer object
    Customer newCustomer(queueNumber, customerName);
    serviceQueue.enqueue(newCustomer); // Add the customer to the queue

    cout << "Customer registered successfully: " << customerName 
         << " (Queue Number: " << queueNumber << ")" << endl;

    // Increment the queue number for the next customer
    queueNumber++;
}

void nextCustomer(Queue& serviceQueue) {
    if (serviceQueue.isEmpty()) {
        cout << "No customers in the queue." << endl;
    } else {
        // Get the next customer
        Customer next;
        serviceQueue.dequeue(next); // Remove the customer from the queue and retrieve their data

        cout << "Serving next customer:" << endl;
        next.print(); // Display customer details
    }
}

void displayCount(Queue& serviceQueue) {
    int count = 0;

    // Temporarily store the current queue
    Queue tempQueue;

    // Traverse the queue to count elements
    while (!serviceQueue.isEmpty()) {
        Customer tempCustomer;
        serviceQueue.dequeue(tempCustomer); // Dequeue each customer
        tempQueue.enqueue(tempCustomer);   // Add to a temporary queue
        count++;
    }

    // Restore the original queue
    while (!tempQueue.isEmpty()) {
        Customer tempCustomer;
        tempQueue.dequeue(tempCustomer);
        serviceQueue.enqueue(tempCustomer);
    }

    cout << "Total number of customers in the queue: " << count << endl;
}

int main()
{
	Queue serviceQueue;
	int queueNumber = 0;
	registerCustomer(serviceQueue, queueNumber);
	
	nextCustomer(serviceQueue);
	
	displayCount(serviceQueue);
}

