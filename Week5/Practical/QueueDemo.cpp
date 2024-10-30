#include <iostream>
#include "Queue.h"  
#include "Queue.cpp" 
using namespace std;
typedef char ItemType;

// int main() {
//     Queue q;
//     q.enqueue('a');
//     q.enqueue('b');
//     ItemType temp;
//     q.getFront(temp);
//     cout << temp << endl;
//     q.displayItems();
//     q.dequeue();
//     q.displayItems();
// }

/* 
Output:
a
a b 
b 
*/

// Function to read user input
string getUserInput() {
    cout << "Enter a string to check if it is a palindrome: ";
    string userInput;
    getline(cin, userInput);
    return userInput;
}

// Function to sanitize the input by removing non-alphabetic characters and converting to lowercase
string sanitizeInput(const string& input) {
    string sanitized = "";
    for (char c : input) {
        if (isalpha(c)) {
            sanitized += tolower(c);
        }
    }
    return sanitized;
}

// Function to enqueue all characters of the sanitized input into a queue
void enqueueCharacters(const string& sanitizedInput, Queue& q) {
    for (char c : sanitizedInput) {
        q.enqueue(c);
    }
}

// Function to determine if the sanitized input is a palindrome
bool isPalindrome(const string& sanitizedInput, Queue& q) {
    int length = sanitizedInput.length();

    // Compare front and corresponding back characters
    for (int i = 0; i < length / 2; i++) {
        ItemType frontChar;
        q.getFront(frontChar);
        q.dequeue();

        // Compare with the corresponding character from the end of the sanitized input
        if (frontChar != sanitizedInput[length - i - 1]) {
            return false;  // Not a palindrome
        }
    }
    return true;  // If all characters match
}

int main() {
    // Step 1: Read user input
    string userInput = getUserInput();

    // Step 2: Sanitize user input
    string sanitizedInput = sanitizeInput(userInput);

    // Step 3: Create a queue and enqueue sanitized input
    Queue q;
    enqueueCharacters(sanitizedInput, q);

    // Step 4: Check if the string is a palindrome
    if (isPalindrome(sanitizedInput, q)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
