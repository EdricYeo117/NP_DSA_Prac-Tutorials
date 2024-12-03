#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

typedef char ItemType;

class Stack
{
private:
	ItemType text[MAX_SIZE];
	int top;

public:
	// constructor
	Stack();	  	  

	// constructor
	~Stack();

	// add new item at the top
	bool push(ItemType item);	

	// remove the item at the top
	bool pop();		

	// remove and return item at the top
	bool pop(ItemType &item);		

	// get the item at the top
	void getTop(ItemType &item);	

	// check if stack is empty
	bool isEmpty();		

	// print the text from top to bottom
	void printInOrder();

	// print the text in the order of insertion
	void printInOrderOfInsertion();
};


