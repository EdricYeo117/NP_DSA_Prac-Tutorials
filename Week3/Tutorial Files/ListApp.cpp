#include "List.h"

// constructor
List::List()
{
    firstNode = nullptr;
    size = 0;
}

// destructor
List::~List()
{
    while (!isEmpty())
        remove(1);
}

// Add an item to the back of the list (append)
bool List::add(ItemType item)
{
    Node *newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;

    if (isEmpty())
        firstNode = newNode; // Insert new node
    else
    {
        Node *temp = firstNode; // Traverse to the last node
        while (temp->next != nullptr)
            temp = temp->next; // Move to the next node
        temp->next = newNode;  // Link to the new node
    }

    size++;
    return true;
}

// Add an item at the specified position in the list (insert)

bool List::add(int index, ItemType item)
{
    if (index < 1 || index > size + 1) // Index out of range
        return false;

    Node *newNode = new Node;
    newNode->item = item;

    if (index == 1)
    {
        newNode->next = firstNode;
        firstNode = newNode;
    }
    else
    {
        Node *current = firstNode;
        // Iterate through each node until we reach the node before the index
        for (int i = 1; i < index - 1; i++)
        {
            current = current->next; // Move to the next node
        }
        newNode->next = current->next; // Link the new node to the next node
        current->next = newNode;       // Link current node to new node
    }
    size++;
    return true;
}

// Remove an item at a specified position in the list
void List::remove(int index)
{
    if (index < 1 || index > size + 1) // Index out of range
        return;

    Node *toDelete;
    if (index == 1)
    {
        toDelete = firstNode;
        firstNode = firstNode->next; // Update head to the next node
    }
    else
    {
        Node *current = firstNode;
        for (int i = 1; i < index - 1; i++)
        {
            current = current->next; // Move to the next node, before the one to be deleted
        }
        toDelete = current->next;
        current->next = toDelete->next; // Link the node before the one to be deleted to the node after the one to be deleted
    }
    delete toDelete;
    size--;
}

// Get an item at a specified position of the list (retrieve)
ItemType List::get(int index)
{
    if (index < 1 || index > size + 1)
    { // Index out of range
        throw out_of_range("Index out of range");
    }

    Node* current = firstNode;
    for (int i = 1; i < index; i++)
    {
        current = current->next; // Move to the next node
    }

    return current->item;
}

// Check if the list is empty
bool List::isEmpty()
{
    return size == 0;
}

// Check the size of the list
int List::getLength()
{
    return size;
}

// Display all the items in the list
void List::print()
{
    Node *current = firstNode;
    while (current != nullptr)
    {
        cout << current->item << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // (a) Create an empty list, nameList
    List nameList;
    
    // (b) Add the name Annie to the list
    nameList.add("Annie");
    // (c) Add the name Jacky to the list
    nameList.add("Jacky");
    // (d) Add the name Wendy to the list
    nameList.add("Wendy");
    // (e) Display the names in the list
    nameList.print();
    // (f) Add the name Brenda to the list at position 2
    nameList.add(2, "Brenda");
    // (g) Display the names in the list
    nameList.print();
    // (h) Remove the name at position 3
    nameList.remove(3);
    // (i) Display the names in the list
    nameList.print();
    // (j) Remove the name in the first position
    nameList.remove(1);
    // (k) Display the names in the list
    nameList.print();
}