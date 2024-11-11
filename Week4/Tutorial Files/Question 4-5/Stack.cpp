#include "Stack.h"

// Default constructor
Stack::Stack()
{
    topNode = nullptr;
}

// Destructor
Stack::~Stack() {
    while (!isEmpty()) {
        ItemType temp;
        pop(temp);
    }
}

// Check if the stack is empty
bool Stack::isEmpty()
{
    return topNode == nullptr;
}

// Push item on top of the stack
bool Stack::push(ItemType item)
{
    Node *newNode = new Node; // Create a new node
    newNode->item = item;     // Store the item in the new node
    newNode->next = topNode;  // Link the new node to the top node
    topNode = newNode;        // Update the top node
    return true;
}

bool Stack::pop()
{
    if (isEmpty())
    {
        return false; // Stack is empty
    }
    else
    {
        Node *temp = topNode;    // Save the top node
        topNode = topNode->next; // Update topNode to the next node
        temp->next = nullptr;
        delete temp;             // Delete the top node
        return true;
    }
}

bool Stack::pop(ItemType &item)
{
    if (isEmpty())
    {
        return false; // Stack is empty
    }
    else
    {
        item = topNode->item; // Retrieve the item
        return pop();         // Pop the top node
    }
}

void Stack::getTop(ItemType &item)
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        item = topNode->item;
    }
}

void Stack::displayInOrder()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        Node *temp = topNode;
        while (temp != nullptr)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}

void Stack::displayInOrderOfInsertion() {
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        Stack tempStack;
        Node* current = topNode;

        // Push all items to a temporary stack
        while (current != nullptr)
        {
            tempStack.push(current->item);
            current = current->next;
        }

        // Display items in the temporary stack
        tempStack.displayInOrder();
    }
}