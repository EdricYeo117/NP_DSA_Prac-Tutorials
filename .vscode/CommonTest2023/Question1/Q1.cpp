// Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "List.h"

using namespace std;

void reverse(List& charList)
{
    // Implement this function to reverse the items in the list
    // Use list operations to reverse the items in the list
    int length = charList.getLength();
    for (int i = 0; i < length / 2; i++)
    {
        ItemType temp = charList.get(i);
        charList.replace(i, charList.get(length - i - 1));
        charList.replace(length - i - 1, temp);
    }
	// Time Complexity: O(n)
}

int main()
{
    List charList;
    string m;

    cout << "Enter a string: ";
    cin >> m;

    for (char c: m)
    {
        charList.add(c);
    }\
    
    cout << "Original List: ";
    charList.display();

    // reverse the list
    reverse(charList);

    cout << "Reversed List: ";
    charList.display();

    return 0;
}

