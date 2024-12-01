#include <iostream>
using namespace std;

// Static global variable to count comparisons
static int comparisons = 0;

// Function to perform sequential search
int sequentialSearch(int dataArray[], int arraySize, int target) {
    comparisons = 0; // Reset comparisons
    for (int i = 0; i < arraySize; i++) {
        comparisons++; // Increment for every comparison
        if (dataArray[i] == target) {
            return i; // Target found, return index
        }
    }
    return -1; // Target not found
}

// Function to perform binary search
int binarySearch(int dataArray[], int arraySize, int target) {
    comparisons = 0; // Reset comparisons
    int low = 0, high = arraySize - 1;

    while (low <= high) {
        comparisons++; // Increment for the mid comparison
        int mid = low + (high - low) / 2; // Avoid potential overflow

        if (dataArray[mid] == target) {
            return mid; // Target found, return index
        }
        else if (dataArray[mid] < target) {
            comparisons++; // Increment for the additional comparison
            low = mid + 1; // Search in the right half
        }
        else {
            comparisons++; // Increment for the additional comparison
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

    // Perform sequential search and display the result
    int result = sequentialSearch(dataArray, SIZE, target);
    if (result != -1) {
        cout << "Sequential Search: Found! Target " << target << " is at index " << result << "." << endl;
    } else {
        cout << "Sequential Search: Not found! Target " << target << " is not in the array." << endl;
    }
    cout << "Sequential Search Comparisons: " << comparisons << endl;

    // Perform binary search and display the result
    result = binarySearch(dataArray, SIZE, target);
    if (result != -1) {
        cout << "Binary Search: Found! Target " << target << " is at index " << result << "." << endl;
    } else {
        cout << "Binary Search: Not found! Target " << target << " is not in the array." << endl;
    }
    cout << "Binary Search Comparisons: " << comparisons << endl;

    return 0;
}
