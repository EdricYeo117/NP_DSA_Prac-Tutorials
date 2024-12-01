#include <iostream>
using namespace std;

// Sequential Search Function (Recursive)
int sequentialSearch(int dataArray[], int arraySize, int start, int target) {
    static int comparisons = 0; // To track comparisons
    comparisons++; // Increment comparisons

    if (start >= arraySize) {
        return -1; // Target not found
    }
    if (dataArray[start] == target) {
        cout << "Sequential Search Comparisons: " << comparisons << endl;
        return start; // Target found
    }
    return sequentialSearch(dataArray, arraySize, start + 1, target); // Recursive call
}

// Binary Search Function (Recursive)
int binarySearch(int dataArray[], int first, int last, int target) {
    static int comparisons = 0; // To track comparisons
    if (first > last) {
        return -1; // Target not found
    }
    comparisons++; // Increment comparisons

    int mid = first + (last - first) / 2; // Avoid potential overflow
    if (dataArray[mid] == target) {
        cout << "Binary Search Comparisons: " << comparisons << endl;
        return mid; // Target found
    }
    if (dataArray[mid] < target) {
        comparisons++; // Increment for additional comparison
        return binarySearch(dataArray, mid + 1, last, target); // Search in the right half
    }
    comparisons++; // Increment for additional comparison
    return binarySearch(dataArray, first, mid - 1, target); // Search in the left half
}

int main() {
    // Array Initialization
    const int SIZE = 1000;
    int dataArray[SIZE];
    for (int i = 0; i < SIZE; i++) {
        dataArray[i] = (i + 1) * 2; // Even numbers from 2 to 2000
    }

    // Prompt the user to enter a target number
    cout << "Enter a target number to search (between 2 and 2000): ";
    int target;
    cin >> target;

    // Sequential Search Test
    int seqResult = sequentialSearch(dataArray, SIZE, 0, target);
    if (seqResult != -1) {
        cout << "Sequential Search: Found at index " << seqResult << endl;
    } else {
        cout << "Sequential Search: Not found" << endl;
    }

    // Binary Search Test
    int binResult = binarySearch(dataArray, 0, SIZE - 1, target);
    if (binResult != -1) {
        cout << "Binary Search: Found at index " << binResult << endl;
    } else {
        cout << "Binary Search: Not found" << endl;
    }

    return 0;
}
