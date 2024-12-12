#pragma once
const int MAX_SIZE = 50;
typedef char ItemType;
class List
{
private:
    ItemType	items[MAX_SIZE];
    int		size; // number of items in the list

public:
    //constructor
    List();

    // add a new item to the back of the list (append)
    bool add(ItemType item);

    // get an item at a specified position of the list
    // 1 <= index <= size
    ItemType get(int index);

    // check and return the size of the list
    int getLength();

    // replace the item at the specified index in the list
    // 1 <= index <= size
    void replace(int index, ItemType item);

    // prints all the items in the list
    void display();
};
