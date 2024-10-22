typedef int* IntPtr;  // Define a type alias for a pointer to int

class List {
private:
    IntPtr array;     // Pointer to dynamically allocated array
    int size;         // Number of elements in the list
    int capacity;     // Maximum capacity of the array

public:
    List(int capacity);  // Constructor to initialize the list with a capacity
    ~List();             // Destructor to free memory
    void displayList();  // Function to display all elements in the list

    /**
     * Purpose: Adds a new integer element to the end of the list.
     *
     * Preconditions:
     * - The list has been initialized with a valid capacity.
     * - The size of the list must be less than its capacity.
     * - The input value must be a valid integer.
     *
     * Postconditions:
     * - If space is available, the new element is added at the end.
     * - The size of the list increases by 1.
     * - If the list is full, no element is added.
     */
    void add(int value);  // Function to add an element to the list
};
