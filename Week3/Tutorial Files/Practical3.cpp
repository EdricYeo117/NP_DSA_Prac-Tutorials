// Practical3.cpp
#include "List.h"
#include "List.cpp"
#include <iostream>
using namespace std;

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

    return 0;
}