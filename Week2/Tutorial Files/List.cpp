#include <iostream>
#include "List.h"
using namespace std;

void List::displayList() {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";  
    }
    cout << endl;  
}