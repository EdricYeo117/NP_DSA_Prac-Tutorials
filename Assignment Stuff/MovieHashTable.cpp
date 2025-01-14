#include "MovieHashTable.h"
#include <iostream>

// -----------------------
//   PRIVATE METHODS
// -----------------------

// Hash function to map years to bucket indices
int MovieHashTable::hashFunction(int year) const {
    return year % TABLE_SIZE;
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
MovieAVLNode* MovieHashTable::searchMovieByTitle(int year, const std::string& title) const {
    int bucketIndex = hashFunction(year);

    if (!buckets[bucketIndex]) {
        std::cerr << "No movies found for the year " << year << ".\n";
        return nullptr;
    }

    return buckets[bucketIndex]->searchMovie(title);
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

// Display all actors in a given movie
void MovieHashTable::displayActorsInMovie(int year, const std::string& movieTitle) const {
    int bucketIndex = hashFunction(year);
    buckets[bucketIndex]->displayActorsInMovie(movieTitle);
}
