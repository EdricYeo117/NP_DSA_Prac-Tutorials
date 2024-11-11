// List.h
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <algorithm> // For std::remove_if

// Template Class Declaration
template <typename T>
class List {
private:
    T* array;          // Pointer to dynamic array of elements
    int size;          // Current number of elements
    int capacity;      // Maximum capacity of the array

    void resize(int newCapacity);  // Helper function to resize the array

public:
    // Constructor
    explicit List(int initialCapacity = 10);

    // Destructor
    ~List();

    // Display all elements (Assumes T has getName() and getTelNo() methods)
    void displayContacts() const;

    // Add a new element (Assumes T can be constructed with name and telNo)
    void add(const std::string& name, const std::string& telNo);

    // Remove an element by telNo (Assumes T has getTelNo() method)
    void remove(const std::string& telNo);

    // Get an element by telNo (Assumes T has getTelNo() method)
    void get(const std::string& telNo) const;
};

// Include the implementation file
#include "List.tpp"

#endif  // LIST_H
