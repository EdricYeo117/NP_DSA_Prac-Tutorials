#include <iostream>
#include <string>
#include <vector>

using namespace std;

//print the numbers in an array in the backward manner
//param array – the array in concern
//param n – number of elements in the array


void printBackward(int array[], int n) {
    // Base case: if n is 0, return
    if (n == 0) {
        return;
    }
    // Recursive case: print the nth element and then call the function with n-1
    cout << array[n - 1] << " ";
    printBackward(array, n - 1);
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    printBackward(array, 5);
    return 0;
}