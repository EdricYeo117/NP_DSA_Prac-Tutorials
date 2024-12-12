// Q5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Dictionary.h"
using namespace std;

int main()
{

    Dictionary dict;

    cout << "Inserting key-value pairs...\n";
    dict.insert(80, "Jeremy");
    dict.insert(65, "Thomas");
    dict.insert(47, "Steven");
    dict.insert(93, "Mary");

    // Print hash value of mark 52
    cout << "Hash value of mark 52: " << dict.hashFunction(52) << "\n";
}
