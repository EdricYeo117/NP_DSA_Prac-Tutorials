#ifndef LIST_H
#define LIST_H

#include "Person.h"
#include <iostream>
#include <string>

class List {
private:
    Person* array;   // Pointer to dynamic array of Person objects
    int size;        // Current number of elements
    int capacity;    // Maximum capacity of the array

    void resize(int newCapacity);  // Helper function to resize the array

public:
    List(int initialCapacity = 10);  // Constructor
    ~List();  // Destructor

    void displayContacts() const;  // Method to display all contacts
    void add(const std::string& name, const std::string& telNo);  // Method to add a contact
    void remove(const std::string& telNo);  // Method to remove a contact by phone number
    void get(const std::string& telNo) const;  // Method to get a contact by phone number
};

#endif  // LIST_H
