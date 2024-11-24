#include <iostream>
#include <string>
#include <vector>

using namespace std;

//return the maximum value in an array of integers
//param array – the array in concern
//param start – start index of the array
//param end   – last index of the array

int maxArray(int array[], int start, int end) {
    // Base case: if start is equal to end, return the value at the start index
    if (start == end) {
        return array[start];
    }
    // Recursive case: find the maximum value between the value at the start index and the maximum value of the rest of the array
    return max(array[start], maxArray(array, start + 1, end));
}

int main() {
    int array[] = {1, 2, 3, 4, 10, 5};
    cout << "Max Value in Array is: " << maxArray(array, 0, 4) << endl;
    return 0;
}
