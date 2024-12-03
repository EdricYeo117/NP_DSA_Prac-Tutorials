int search(int dataArray[], int arraySize, int start, int target) {
    // Base case: if we have reached the end of the array or the size limit
    if (start >= arraySize) {
        return -1; // Target not found
    }

    // Check if the current element matches the target
    if (dataArray[start] == target) {
        return start; // Return the index of the target
    }

    // Recursive case: check the next element
    return search(dataArray, arraySize, start + 1, target);
}