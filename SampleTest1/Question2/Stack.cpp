#include "Stack.h"

Stack::Stack() { top = -1; }

Stack::~Stack() { }

bool Stack::push(ItemType item)
{
    bool success = top < MAX_SIZE - 1;
    if (success)
    {
        top++;
        text[top] = item;
    }

    return success;
}

bool Stack::pop()
{
    bool success = !isEmpty();
    if (success)
        top--;

    return success;
}

bool Stack::pop(ItemType& item)
{
    bool success = !isEmpty();
    if (success)
    {
        item = text[top];
        top--;
    }
    return success;
}


void Stack::getTop(ItemType& item)
{
    bool success = !isEmpty();
    if (success)
        item = text[top];
}

bool Stack::isEmpty() { return top < 0; }

void Stack::printInOrder()
{
    for (int i = top; i >= 0; i--)
        cout << text[i];
}

void Stack::printInOrderOfInsertion()
{
    for (int i = 0; i <= top; i++)
        cout << text[i];
}