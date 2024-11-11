#include <iostream>
#include <string>
#include "List.h"
#include "Person.h"
#include <vector> // Include vector for dynamic array
#include "Module.h"

using namespace std;

// Main menu function
void mainMenu()
{
    List<Person> contactList;  // Create an instance of List to manage contacts
    int option;

    do
    {
        cout << "\n---------------- Main Menu ----------------\n"
             << "[1] List the phone numbers\n"
             << "[2] Add a new contact\n"
             << "[3] Remove a contact\n"
             << "[4] Search for a phone number\n"
             << "[0] Exit\n"
             << "-------------------------------------------\n"
             << "Enter your option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            contactList.displayContacts();  // List contacts using List class method
            break;
        case 2:
        {
            string name, phone;
            cout << "Enter contact name: ";
            cin >> ws; // Clear input buffer
            getline(cin, name);
            cout << "Enter phone number: ";
            cin >> phone;
            contactList.add(name, phone);  // Add a contact
            break;
        }
        case 3:
        {
            string phone;
            cout << "Enter the phone number to remove: ";
            cin >> phone;
            contactList.remove(phone);  // Remove a contact by phone number
            break;
        }
        case 4:
        {
            string phone;
            cout << "Enter the phone number to search: ";
            cin >> phone;
            contactList.get(phone);  // Get contact by phone number
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    } while (option != 0);
}

void calculateModules() {
    // Create a vector to hold Module objects
    std::vector<Module> modules;

    // Add modules to the list
    modules.emplace_back("Programming", 80, 70, 90);
    modules.emplace_back("Mathematics", 70, 60, 80);
    modules.emplace_back("Database", 85, 75, 95);

    // Calculate and display total scores
    std::cout << "Module Scores:\n";
    for (const auto &module : modules) {
        std::cout << "Module: " << module.getName()
                  << ", Total: " << module.calculateTotal() << "\n";
    }
}


int main()
{
    calculateModules();  // Call the calculateModules function
    mainMenu();  // Call the main menu function
    return 0;
}
