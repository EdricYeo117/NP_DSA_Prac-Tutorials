// PQueue.cpp - Implementation of PQueue ADT (Pointer-based)
#include "PQueue.h"

PQueue::PQueue()
{
	frontNode = NULL;
    backNode = NULL;
}

PQueue::~PQueue() { }

void PQueue::enqueue(ItemType anItem, PriorityType p)
{
        Node* new_node = new Node;
		new_node->item = anItem;
		new_node->priority = p;
		new_node->next = nullptr;

        // If the queue is empty or the new node has a higher priority than the front
        if (isEmpty() || frontNode->priority < p) {
            new_node->next = frontNode;
            frontNode = new_node;
			return;
        } else {
            // Find the correct position to insert the new node
            Node* temp = frontNode;
            while (temp->next != nullptr && temp->next->priority >= priority) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
			return;
        }
}

bool PQueue::isEmpty() { return frontNode == NULL; }

void PQueue::print()
{
	Node* temp = frontNode;
	while (temp != NULL)
	{
		cout << "Item: " << temp->item << " Priority : " << temp->priority << endl;
		temp = temp->next;
	}
		
}

