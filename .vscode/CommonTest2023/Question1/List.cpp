// List.cpp - Implementation of List ADT using Array
#include <iostream>
#include "List.h"  // header file
using namespace std;

// constructor
List::List() { size = 0; }

// add an item to the back of the list (append)
bool List::add(ItemType item)
{
	bool success = size < MAX_SIZE;
	if (success)
	{
		items[size] = item;    // add to the end of the list
		size++;                // increase the size by 1
	}
	return success;
}

// get an item at a specified position of the list (retrieve)
ItemType List::get(int index)
{
	bool success = (index >= 0) && (index < size);
	if (success)
		return items[index];
	else
		return ItemType();  // now returns T which is a Person
}                         // things to change because using typedef


// check the size of the list

int List::getLength() { return size; }


// replace the  item in the specified index in the list
void List::replace(int index, ItemType item)
{
	items[index] = item;
}

// display the items in the list
void List::display()
{
	for (int i = 0; i < size; i++)
	{
		cout << items[i]  << " "; 
	}
	cout << endl;
	
}
