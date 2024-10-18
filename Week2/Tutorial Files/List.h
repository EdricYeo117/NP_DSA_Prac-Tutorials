class List {
private:
    int* array;     // Pointer to dynamically allocated array
    int size;       // Number of elements in the list
    int capacity;   // Maximum capacity of the array

public:
    List(int capacity);  // Constructor to initialize the list with a capacity
    ~List();             // Destructor to free memory
    void displayList();  // Function to display all elements in the list
    void add(int value); // Function to add an element (optional)
    // Other member functions...
};

