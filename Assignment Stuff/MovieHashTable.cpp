#include "MovieHashTable.h"
#include <iostream>

// -----------------------
//   PRIVATE METHODS
// -----------------------

// Hash function to map years to bucket indices
int MovieHashTable::hashFunction(int year) const {
    // Ensures the hash index is within the bounds of TABLE_SIZE
    return abs(year % TABLE_SIZE);
}

// -----------------------
//   PUBLIC METHODS
// -----------------------

// Constructor: initialize each bucket with a new AVL tree
MovieHashTable::MovieHashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        buckets[i] = new MovieAVLTree();
    }
}

// Destructor: delete each AVL tree
MovieHashTable::~MovieHashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        delete buckets[i];
    }
}

int MovieHashTable::getSize() const {
    return TABLE_SIZE;
}

// Insert a movie into the appropriate bucket's AVL tree
void MovieHashTable::insertMovie(const std::string& title,
                                 const std::string& plot,
                                 int year,
                                 double rating,
                                 const std::vector<std::tuple<std::string, std::string, std::string>>& actorDetails) {
    int bucketIndex = hashFunction(year);
    buckets[bucketIndex]->insertMovie(title, plot, year, rating, actorDetails);
}

// Search for a movie by title within a specific year
MovieAVLNode* MovieHashTable::searchMovieByTitle(int year, const string& title) const {
    int bucketIndex = hashFunction(year);
    if (!buckets[bucketIndex]) {
        cerr << "No movies found for the given year: " << year << endl;
        return nullptr;
    }

    // Get the root of the AVL tree for this bucket
    MovieAVLNode* root = buckets[bucketIndex]->getRoot();
    return buckets[bucketIndex]->searchMovie(root, title);
}

// Add an actor to a specific movie
void MovieHashTable::addActorToMovie(int year,
                                     const std::string& movieTitle,
                                     const std::string& actorName,
                                     const std::string& yearOfBirth,
                                     const std::string& rating) {
    int bucketIndex = hashFunction(year);
    buckets[bucketIndex]->addActorToMovie(movieTitle, actorName, yearOfBirth, rating);
}

// Display all movies made in the last 'recentYears' years
void MovieHashTable::displayMoviesByYear(int recentYears) const {
    bool hasMovies = false;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        // Check if the bucket has movies
        if (buckets[i]) {
            hasMovies = true;
            buckets[i]->displayMoviesByYear(recentYears);
        }
    }
    if (!hasMovies) {
        std::cout << "No movies found in the last " << recentYears << " years.\n";
    }
}

void MovieHashTable::displayAllMovies() const {
    bool hasMovies = false; // Flag to track if there are any movies
    cout << "Displaying all movies in the hash table:\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (buckets[i]) { // If the bucket has an AVL tree
            buckets[i]->displayMoviesByYear(0); // Passing 0 ensures all movies are displayed
            hasMovies = true;
        }
    }
    if (!hasMovies) {
        cout << "No movies found in the hash table.\n";
    }
}

// Display all actors in a given movie
void MovieHashTable::displayActorsInMovie(int year, const std::string& movieTitle) const {
    int bucketIndex = hashFunction(year);
    buckets[bucketIndex]->displayActorsInMovie(movieTitle);
}

// Get a specific bucket (returns nullptr if index is out of bounds)
MovieAVLTree* MovieHashTable::getBucket(int index) const {
    // Check for valid bucket index
    if (index < 0 || index >= TABLE_SIZE) {
        std::cerr << "Invalid bucket index: " << index << ".\n";
        return nullptr;
    }

    // Return the bucket at the specified index
    return buckets[index];
}

// Retrieve the bucket (MovieAVLTree) for a given year
MovieAVLTree* MovieHashTable::getBucketByYear(int year) const {
    int bucketIndex = hashFunction(year); // Use private hashFunction
    return getBucket(bucketIndex);       // Use existing getBucket method
}
