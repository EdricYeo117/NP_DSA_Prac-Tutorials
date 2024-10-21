#include <iostream>
#include "List.h"

using namespace std;

// Constructor
List::List(int initialCapacity) : size(0), capacity(initialCapacity) {
    array = new Person[capacity];
}

// Destructor
List::~List() {
    delete[] array;
}

// Resize the array when capacity is exceeded
void List::resize(int newCapacity) {
    Person* newArray = new Person[newCapacity];
    for (int i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

// Display all contacts
void List::displayContacts() const {
    if (size == 0) {
        cout << "No contacts available.\n";
    } else {
        cout << "\nContacts:\n";
        for (int i = 0; i < size; ++i) {
            cout << "Name: " << array[i].getName()
                 << ", Phone: " << array[i].getTelNo() << "\n";
        }
    }
}

// Add a new contact
void List::add(const std::string& name, const std::string& telNo) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    array[size++] = Person(name, telNo);
    cout << name << " has been added.\n";
}

// Remove a contact by phone number
void List::remove(const std::string& telNo) {
    for (int i = 0; i < size; ++i) {
        if (array[i].getTelNo() == telNo) {
            cout << array[i].getName() << " has been removed.\n";
            // Shift elements to fill the gap
            for (int j = i; j < size - 1; ++j) {
                array[j] = array[j + 1];
            }
            --size;
            return;
        }
    }
    cout << "Contact not found.\n";
}

// Search for a contact by phone number
void List::get(const std::string& telNo) const {
    for (int i = 0; i < size; ++i) {
        if (array[i].getTelNo() == telNo) {
            cout << "Found: " << array[i].getName()
                 << " - " << array[i].getTelNo() << "\n";
            return;
        }
    }
    cout << "Contact not found.\n";
}
