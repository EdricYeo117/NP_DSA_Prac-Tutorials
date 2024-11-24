#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack back_stack;
    string url;
    string temp;

    while (true) {
        cout << "[1] Visit URL\n[2] Back\n[0] Exit\nYour Choice: ";
        cin >> temp;

        // Input validation
        if (temp.empty()) {
            cout << "Input cannot be empty." << endl;
            continue;
        }

        if (temp == "0") {
            break; // Exit the loop
        } else if (temp == "1") {
            cout << "Enter URL: ";
            cin >> url; // Get URL from user
            
            // Check for empty URL
            if (url.empty()) {
                cout << "URL cannot be empty. Please enter a valid URL." << endl;
                continue;
            }

            back_stack.push(url); // Push URL to back_stack
            cout << "Visited: " << url << endl;
        } else if (temp == "2") {
            string previous_url; // URL to go back to
            if (back_stack.pop(previous_url)) { // Correct method call
                cout << "Back to: " << previous_url << endl;
            } else {
                cout << "No more URLs to go back to." << endl;
            }
        } else {
            cout << "Invalid choice." << endl; // Handle invalid input
        }
    }
    return 0;
}
