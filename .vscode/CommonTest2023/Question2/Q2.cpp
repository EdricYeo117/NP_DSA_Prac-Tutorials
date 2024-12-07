// Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    int anArray[] = { 4, 6, 2, 8, 9 };
    List aList(anArray, 5);
    cout << "Here is the original list:";
    aList.display();
    int item = aList.removeFirst();
    cout << "The first item removed is:" << item << endl;
    aList.display();
    List newList;
    aList.duplicateList(newList);
    cout << "Here is the duplicated list:";
    newList.display();
}
