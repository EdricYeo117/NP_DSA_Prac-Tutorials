// Dictionary.cpp - Implementation of Dictonary ADT using Hash Table with separate chaining

#include "Dictionary.h" // firstNodeer file
#include <queue>
#include <unordered_set>

using namespace std;

// constructor
Dictionary::Dictionary()
{
	for (int i = 0; i < MAX_SIZE; i++)
		items[i] = NULL;
	size = 0;
}

// destructor
Dictionary::~Dictionary()
{
}

// get the hash value for the given search key
int Dictionary::hash(KeyType key)
{
	int hashValue = 0;
	vector<int> weights;
	weights.add(7);
	for (int i = 0; i < 6; i++)
	{
		for (char c : key)
		{
			int keyValue = c * weights[i];
			hashValue += keyValue;
		}
	}
	int remainder = hashValue % 11;
	return remainder;
}

// add a new item with a specified key in the Dictionary
void Dictionary::add(KeyType newKey, ItemType newItem)
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
		// Value to check if linked list is more than 50
		int listNodes = 0;
		// Traverse the linked list until the end
		while (current != nullptr)
		{
			if (listNodes >= 50) {
				// Add 1 to index
				index =+ 1;
			}
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
				if (listNodes < 50)
				{
					current->next = newNode;
					size++;
					return true;
				}
			}

			// move to the next node
			current = current->next;
			listNodes++;
		}
	}
	// If failed delete node in case of memory leak
	delete newNode;
	return false;
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

// print the Dictionary
void Dictionary::print()
{
	for (int i = 0; i < MAX_SIZE; i++)
		if (items[i] != NULL)
		{
			Node *current = items[i];
			while (current)
			{
				cout << current->key << " - " << current->item << endl;
				current = current->next;
			}
		}
}