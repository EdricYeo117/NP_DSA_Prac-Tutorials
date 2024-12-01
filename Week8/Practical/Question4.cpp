#include <iostream>
using namespace std;

// Function to perform binary search iteratively
int binarySearch(int dataArray[], int arraySize, int target) {
    int low = 0, high = arraySize - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid potential overflow

        if (dataArray[mid] == target) {
            return mid; // Target found, return index
        }
        else if (dataArray[mid] < target) {
            low = mid + 1; // Search in the right half
        }
        else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; 
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

    // Step (e): Invoke the binary search method and display the result
    int result = binarySearch(dataArray, SIZE, target);

    if (result != -1) {
        cout << "Found! Target " << target << " is at index " << result << "." << endl;
    } else {
        cout << "Not found! Target " << target << " is not in the array." << endl;
    }

    return 0;
}
