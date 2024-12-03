
#include <string>
#include <iostream>
#include "Dictionary.h"

using namespace std;
typedef string ItemType;
typedef string KeyType;

// Constructor
Dictionary::Dictionary() : size(0)
{
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        items[i] = nullptr;
    }
}

// Destructor
Dictionary::~Dictionary()
{
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        Node *current = items[i];
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
}

int Dictionary::hash(KeyType key)
{
    int hashValue = 0;
    for (char c : key)
    {
        int val = charvalue(c);
        if (val == -1)
        {
            // Handle non-alphabetic characters
            continue;
        }
        hashValue = ((hashValue * 52) + val) % MAX_SIZE;
    }
    return (hashValue + MAX_SIZE) % MAX_SIZE; // Ensures non-negative index
}

// add a new item with the specified key to the Dictionary
bool Dictionary::add(KeyType newKey, ItemType newItem)
{
    // get the index of the new key
    int index = hash(newKey);
    // create a new node
    Node *newNode = new Node;
    // assign the key and item to the new node
    newNode->key = newKey;
    // assign the item to the new node
    newNode->item = newItem;
    // assign the next pointer to the new node
    newNode->next = nullptr;
    // if the index is empty
    if (items[index] == nullptr)
    {
        // assign the new node to the index
        items[index] = newNode;
        size++;
        return true;
    }
    else
    {
        // Create a pointer to the current node residing in the index
        Node *current = items[index];
        // Traverse the linked list until the end
        while (current != nullptr)
        {
            // if the key already exists
            if (current->key == newKey)
            {
                // delete the new node, clear the memory
                delete newNode;
                return false;
            }
            // if at the end of list, attach new node
            if (current->next == nullptr)
            {
                current->next = newNode;
                size++;
                return true;
            }

            // move to the next node
            current = current->next;
        }
    }
    // If failed delete node in case of memory leak
    delete newNode;
    return false;
}

// remove an item with the specified key in the Dictionary
void Dictionary::remove(KeyType key)
{
    // get the index of the key
    int index = hash(key);
    // Get the current node
    Node *current = items[index];
    // Get the previous node
    Node *previous = nullptr;

    // Traverse the linked list
    while (current != nullptr)
    {
        // If statement to check if the key is found
        if (current->key == key)
        {
            // If the previous node is null, check if it is the first node
            if (previous == nullptr)
            {
                // If it is the first node, assign the next node to index
                items[index] = current->next;
            }
            else
            {
                // If it is not the first node, assign the next node to the previous node
                // This changes the pointer of next for previous node, to be the same pointer of next for current node (skips over current node)
                previous->next = current->next;
            }
            delete current;
            size--;
            return;
        }
        // Move to the next node
        previous = current;
        current = current->next;
    }
    cerr << "Key not found" << endl;
}

// get an item with the specified key in the Dictionary (retrieve)
ItemType Dictionary::get(KeyType key)
{
    // get the index of the key
    int index = hash(key);
    // Get the current node
    Node *current = items[index];
    // Traverse the linked list
    while (current != nullptr)
    {
        // If statement to check if the key is found
        if (current->key == key)
        {
            return current->item;
        }
        else
        {
            // Move to the next node
            current = current->next;
        }
    }
    throw "Key not found";
}

// check if the Dictionary is empty
bool Dictionary::isEmpty()
{
    return size == 0;
}

// check the size of the Dictionary
int Dictionary::getLength()
{
    return size;
}

//------------------- Other useful functions -----------------

// display the items in the Dictionary
void Dictionary::print()
{
    // For loop to iterate through the array
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (items[i] != nullptr)
        {
            cout << "Bucket " << i << ": ";
            // Get the current node
            Node *current = items[i];
            // Traverse the linked list
            while (current != nullptr)
            {
                // Print the key and item
                cout << current->key << " " << current->item << endl;
                // Move to the next node
                current = current->next;
            }
        }
    }
}

int Dictionary::charvalue(char c) const
{
    if (isalpha(c))
    {
        if (isupper(c))
            return (int)c - (int)'A';
        else
            return (int)c - (int)'a' + 26;
    }
    else
        return -1;
}
