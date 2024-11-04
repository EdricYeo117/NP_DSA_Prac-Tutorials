#include "Dictionary.cpp"
#include "Dictionary.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Dictionary phoneBook;
    phoneBook.add("Pamela", "64606722");
    phoneBook.add("PohSeng", "64608687");
    phoneBook.add("Wesley", "64607237");
    phoneBook.add("WeeChong", "64606854");
    phoneBook.print();
    phoneBook.add("Saiful", "64608206");
    cout << "After adding Saiful" << endl;
    phoneBook.print();  
    phoneBook.add("PohSeng", "12345678");
    phoneBook.remove("Eugune");
    cout << "After removing Eugene" << endl;
    phoneBook.print();
}