// Q2.cpp 
#include <iostream>
#include <string>
using namespace std;

#include "Stack.h"

void displayMenu();             // function to display main menu
void compose(Stack& s);         // function to enter the text
void undo(Stack& s);            // function to undo changes 
void clear(Stack& s);           // function to clear the text

int main()
{
    int option = 1;
    Stack s;

    while (option != 0)
    {
        displayMenu();
        cin >> option;
        if (option == 1)
            compose(s);
        else
            if (option == 2)
                undo(s);
            else
                if (option == 3)
                    clear(s);
                else
                    cout << "Invalid option! Please try again." << endl;
    }

    return 0;
}

// function to display main menu
void displayMenu()
{
    cout << endl;
    cout << "Main Menu           " << endl;
    cout << "--------------------" << endl;
    cout << "[1] Compose         " << endl;
    cout << "[2] Undo            " << endl;
    cout << "[3] Clear           " << endl;
    cout << "[0] Exit            " << endl;
    cout << "--------------------" << endl;
    cout << "Enter your option: ";
}

// 2(a)
void compose(Stack& s) {
    cout << "Option 1: Compose" << endl;
    cout << "Enter your text (end with Enter): ";
    string input;
    cin.ignore(); // Clear input buffer
    getline(cin, input); // Get user input as a string

    for (char c : input) {
        if (!s.push(c)) {
            cout << "Stack overflow. Could not add: " << c << endl;
            break;
        }
    }
    cout << "Text added: " << input << endl;
}

// 2(b)
void undo(Stack& s) {
    cout << "Option 2: Undo" << endl;

    if (s.isEmpty()) {
        cout << "No text to undo." << endl;
        return;
    }

    char undoneChar;
    do {
        s.getTop(undoneChar); // Get the character at the top of the stack
        cout << "Undoing: " << undoneChar << endl;
        s.pop(); // Remove the character from the stack

        cout << "Enter 1 to undo again, 0 to quit: ";
        int choice;
        cin >> choice;

        if (choice == 0) break;
    } while (!s.isEmpty());

    if (s.isEmpty()) {
        cout << "The text is now empty." << endl;
    } else {
        cout << "Remaining text: ";
        s.printInOrderOfInsertion(); // Display the remaining text
        cout << endl;
    }
}

// 2(c)
void clear(Stack& s) {
    cout << "Option 3: Clear" << endl;

    while (!s.isEmpty()) {
        s.pop(); // Continuously pop until the stack is empty
    }
    cout << "The text is cleared." << endl;
}