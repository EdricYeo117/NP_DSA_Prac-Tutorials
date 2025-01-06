// List.cpp - Implementation of List ADT using Array
#include "List.h" //header file
#include <iostream>

using namespace std;
// constructor
List::List()
{
   size = 0;
   for (int i = 0; i < MAX_SIZE; i++)
      items[i] = 0;
}

// add a new item to the back of the list (append)
bool List::add(ItemType newItem)
{
   bool success = size < MAX_SIZE;
   if (success)
   {
      items[size] = newItem; // add to the end of the list
      size++;                // increase the size of the list by one
   }
   return success;
}

// add a new item at a specified position in the list (insert)
bool List::add(int index, ItemType newItem)
{
   bool success = (index >= 0) && (index <= size) && (size < MAX_SIZE);
   if (success)
   { // make room for new item by shifting all items at
      // positions >= index toward the end of the
      // List (no shift if index == size)
      for (int pos = size; pos >= index; pos--)
         items[pos] = items[pos - 1];
      // insert new item
      items[index] = newItem;
      size++; // increase the size of the list by one
   }
   return success;
}

void List::rotate(int num)
{
   // Array Implementation of List to shift
   // Obtain total size first
   int totalSize = getLength();

   // Iterate through the array
   for (int i = num; i <= num; i++)
   {
      for (int i = 0; i < totalSize; i++)
      {
         ItemType dataItem = 0;
         dataItem = items[i];
         if ( i - 1 < 0) {
            items[totalSize] = dataItem;
         } else {
            items[i - 1] = dataItem;
         }
      }
   }
}

// get an item at a specified position of the list (retrieve)
ItemType List::get(int index)
{
   ItemType dataItem = 0;
   bool success = (index >= 0) && (index < size);
   if (success)
      dataItem = items[index];

   return dataItem;
}

// check the size of the list
int List::getLength()
{
   return size;
}

void List::print()
{
   for (int i = 0; i < size; i++)
      cout << get(i) << endl;
}