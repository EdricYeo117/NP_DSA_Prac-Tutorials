// Stack.cpp (Pointer-based implementation)
#include "Stack.h"		// Specification of Stack ADT

Stack::Stack() { topNode = NULL; }

Stack::~Stack() { }

bool Stack::push(ItemType item)
{
	Node* new_node = new Node;
	new_node->item = item;
	new_node->next = topNode;
	topNode = new_node;
	return true;
}

bool Stack::pop()
{
	bool success = !isEmpty();	// ensure stack is NOT empty
	if (success)
	{
		// stack is not empty; delete top
		Node* temp = topNode;
		topNode = topNode->next;
		// return deleted node to system
		delete temp;
		return true;
	}
	else
		return false;
}

// version 1
ItemType Stack::getTop()
{
	bool success = !isEmpty();	// ensure stack is NOT empty
	if (success)
		return topNode->item;
	else
		return -1;
};

// version 2
void Stack::getTop(ItemType& item)
{
	bool success = !isEmpty();	// ensure stack is NOT empty
	if (success)
		item = topNode->item;
};

bool Stack::isEmpty() { return (topNode == NULL); }


