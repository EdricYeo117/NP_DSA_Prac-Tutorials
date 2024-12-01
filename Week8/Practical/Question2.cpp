#include <iostream>
using namespace std;

// Function to perform sequential search
int search(int dataArray[], int arraySize, int target) {
    for (int i = 0; i < arraySize; i++) {
        if (dataArray[i] == target) {
            return i; // Target found, return the index
        }
    }
    return -1; // Target not found, return -1
}

int main() {
    // Step (a): Declare an integer array of size 1000
    const int SIZE = 1000;
    int dataArray[SIZE];

    // Step (b): Initialize the array with even numbers from 2 to 2000
    for (int i = 0; i < SIZE; i++) {
        dataArray[i] = (i + 1) * 2;
    }

    // Step (c): Prompt the user to enter a target number to search
    cout << "Enter a target number to search (between 2 and 2000): ";
    int target;
    
    // Step (d): Read the number entered by the user
    cin >> target;

    // Step (e): Invoke the search method and display the result
    int result = search(dataArray, SIZE, target);

    if (result != -1) {
        cout << "Found! Target " << target << " is at index " << result << "." << endl;
    } else {
        cout << "Not found! Target " << target << " is not in the array." << endl;
    }

    return 0;
}
