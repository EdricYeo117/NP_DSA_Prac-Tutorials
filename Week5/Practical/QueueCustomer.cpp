#include "Queue.h"
#include "Queue.cpp"
#include "Customer.h"
#include "Customer.cpp"
#include <iostream>
#include <string>
#include <queue> 
#include <cstdlib> 
#include <ctime> 
#include "Customer.h"
#include "Queue.h"

using namespace std;

void simulateCheckout(int simulatedMinutes) {
    Queue<Customer> customerQueue;
    int totalCustomerServed = 0;
    int totalWaitTime = 0;
    int currentTime = 0;
    int nextCustomerNum = 1;

    // Random number generator
    srand(time(0));

    // Simulation Loop, use while loop
    while (currentTime < simulatedMinutes) {
        // Add 1 minute to the current time
        currentTime++;
        cout << "Minute " << currentTime << endl;

        // Serve customer if queue is not empty (Step 1)
        if (!customerQueue.isEmpty()) {
            Customer frontCustomer;
            customerQueue.getFront(frontCustomer);
            customerQueue.dequeue();
            totalCustomerServed++;

            // Calculate wait time
            int waitTime = currentTime - frontCustomer.getQueueNum();
            totalWaitTime += waitTime;
            cout << "Customer " << frontCustomer.getName() << " served in " << waitTime << " minutes." << endl;
        } else {
            cout << "No customer to serve." << endl;
        }

         // Determine how many customers arrive
        int numArrivals = rand() % 4; // Random number between 0 and 3
        if (numArrivals == 1) {
            // One customer arrives
            string customerName;
            cout << "Enter customer name: ";
            cin >> customerName;
            Customer newCustomer(customerName, currentTime);
            customerQueue.enqueue(newCustomer);
            cout << "1 customer (" << customerName << ") arrived." << endl;
        } else if (numArrivals == 2) {
            // Two customers arrive
            for (int i = 0; i < 2; i++) {
                string customerName;
                cout << "Enter customer name: ";
                cin >> customerName;
                Customer newCustomer(customerName, currentTime);
                customerQueue.enqueue(newCustomer);
                cout << "Customer " << customerName << " arrived." << endl;
            }
        } else {
            cout << "No customers arrive." << endl;
        }

        // Display queue status
        cout << "Current queue length: " << (customerQueue.isEmpty() ? 0 : currentTime - totalCustomerServed) << endl;
    }

        // Display statitics
        // Display average wait time in simulation
        if (totalCustomerServed > 0) {
            cout << "In this " <<simulatedMinutes << "-min period, the average wait time is " << totalWaitTime / totalCustomerServed << " minutes." << endl;
        } else {
            cout << "No customer served." << endl;
        }
        // Display number of customers served
            cout << totalCustomerServed << " customers served." << endl;
    }

int main() {
    int simulatedMinutes;
    cout << "Enter the number of minutes to simulate: ";
    cin >> simulatedMinutes;
    // Call the simulateCheckout function
    simulateCheckout(simulatedMinutes);
    return 0;
}


