// List.tpp
#ifndef LIST_TPP
#define LIST_TPP

#include "List.h"

// Constructor
template <typename T>
List<T>::List(int initialCapacity) : size(0), capacity(initialCapacity) {
    array = new T[capacity];
}

// Destructor
template <typename T>
List<T>::~List() {
    delete[] array;
}

// Resize the array when capacity is exceeded
template <typename T>
void List<T>::resize(int newCapacity) {
    T* newArray = new T[newCapacity];
    for (int i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

// Display all contacts
template <typename T>
void List<T>::displayContacts() const {
    if (size == 0) {
        std::cout << "No contacts available.\n";
    } else {
        std::cout << "\nContacts:\n";
        for (int i = 0; i < size; ++i) {
            std::cout << "Name: " << array[i].getName()
                      << ", Phone: " << array[i].getTelNo() << "\n";
        }
    }
}

// Add a new contact
template <typename T>
void List<T>::add(const std::string& name, const std::string& telNo) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    array[size++] = T(name, telNo);  // Assumes T has a constructor taking (std::string, std::string)
    std::cout << name << " has been added.\n";
}

// Remove a contact by phone number
template <typename T>
void List<T>::remove(const std::string& telNo) {
    for (int i = 0; i < size; ++i) {
        if (array[i].getTelNo() == telNo) {  // Assumes T has getTelNo() method
            std::cout << array[i].getName() << " has been removed.\n";
            // Shift elements to fill the gap
            for (int j = i; j < size - 1; ++j) {
                array[j] = array[j + 1];
            }
            --size;
            return;
        }
    }
    std::cout << "Contact not found.\n";
}

// Search for a contact by phone number
template <typename T>
void List<T>::get(const std::string& telNo) const {
    for (int i = 0; i < size; ++i) {
        if (array[i].getTelNo() == telNo) {  // Assumes T has getTelNo() method
            std::cout << "Found: " << array[i].getName()
                      << " - " << array[i].getTelNo() << "\n";
            return;
        }
    }
    std::cout << "Contact not found.\n";
}

#endif  // LIST_TPP
