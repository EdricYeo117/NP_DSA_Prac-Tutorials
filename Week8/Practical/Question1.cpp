#include <iostream>
#include <string>

using namespace std;

// Function to perform sequential search
// Returns the index of the element if found

int search (int dataArray[], int arraySize, int target) {
    for (int i = 0; i < arraySize; i++) {
        if (dataArray[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int dataArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arraySize = sizeof(dataArray) / sizeof(dataArray[0]);
    int target = 5;
    int result = search(dataArray, arraySize, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}