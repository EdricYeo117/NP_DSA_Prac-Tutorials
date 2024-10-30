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

int main() {
    // Read User Input
    cout << "Enter a string, check if it is a palindrome: ";
    string userInput;
    getline(cin, userInput);

    // Create a queue
    Queue q;

    // Convert string to lowercase chars, enqueue each char
    string sanitisedInput = "";
    for (int i = 0; i < userInput.length(); i++) {
        if (isalpha(userInput[i])) {
            sanitisedInput += tolower(userInput[i]);
            q.enqueue(tolower(userInput[i]));
        }
    }

    // Check if the string is a palindrome
    bool isPalindrome = true;
    int length = sanitisedInput.length();

    // Compare front and back characters using queue,
    for (int i = 0, i < length / 2; i++) {
        ItemType frontChar;
        q.getFront(frontChar);
        q.dequeue();

        // Compare with the corresponding character from the end of sanistised input
        if (frontChar != sanitisedInput[length - i - 1]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
