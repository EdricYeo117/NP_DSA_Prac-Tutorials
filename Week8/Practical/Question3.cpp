#include <iostream>
using namespace std;

// Function to perform binary search iteratively
// Returns the index of the target if found, otherwise -1
int binarySearch(int dataArray[], int arraySize, int target) {
    int low = 0, high = arraySize - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // To prevent overflow

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
    int dataArray[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; 
    int arraySize = sizeof(dataArray) / sizeof(dataArray[0]);
    int target;

    cout << "Enter a target number to search: ";
    cin >> target;

    int result = binarySearch(dataArray, arraySize, target);

    if (result != -1) {
        cout << "Target " << target << " found at index " << result << endl;
    } else {
        cout << "Target " << target << " not found in the array" << endl;
    }

    return 0;
}
