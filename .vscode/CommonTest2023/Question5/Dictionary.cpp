#include "Dictionary.h"
#include <stdexcept>


using namespace std;
    
// constructor
Dictionary::Dictionary()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = nullptr;
    }
}

// destructor
Dictionary::~Dictionary() 
{
    for (int i = 0; i < SIZE; i++) 
    {
        while (table[i] != nullptr) 
        {
            KeyValuePair* temp = table[i];
            table[i] = table[i]->next;
            delete temp;
        }
    }
}

// returns the hash value of a given key.
int Dictionary::hashFunction(int key)
{
    if (key >= 80 && key < 100) {
        return 0; // Grade A
    } else if (key >= 70 && key < 80) {
        return 1; // Grade B
    } else if (key >= 60 && key < 70) {
        return 2; // Grade C
    } else if (key >= 50 && key < 60) {
        return 3; // Grade D
    } else if (key < 50) {
        return 4; // Grade F
    }

    // Handle invalid marks (e.g., < 0 or >= 100)
    throw invalid_argument("Invalid mark. Key must be within 0 to 100.");
}

// inserts a new key-value pair to the table array.
void Dictionary::insert(int key, string value)
{

    // Compute hash value
    int hashValue = hashFunction(key);

    // Create new node to store key-value pair
    KeyValuePair* newKVP = new KeyValuePair;
    newKVP->key = key;
    newKVP->value = value;
    newKVP->next = nullptr;

    // If the bucket is empty, insert the new node
    if (table[hashValue] == nullptr) 
    {
        table[hashValue] = newKVP;
    } else {
        // Collision handling
        KeyValuePair* current = table[hashValue];
        while (current->next != nullptr) 
        {
            if (current->key == key) 
            {
                // Update value if key already exists
                current->value = value;
                delete newKVP;
                return;
            }
            current = current->next;
        }

        // Check last node for an existing key
        if (current->key == key) 
        {
            current->value = value;
            delete newKVP;
        } else {
            current->next = newKVP;
        }
    }
}



