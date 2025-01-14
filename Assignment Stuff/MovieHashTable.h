#ifndef MOVIE_HASH_TABLE_H
#define MOVIE_HASH_TABLE_H

#pragma once
#include "MovieAVLTree.h"
#include <vector>
#include <tuple>
#include <string>

// A hash table with buckets as AVL trees
class MovieHashTable {
private:
    static const int TABLE_SIZE = 101; // Hash table size
    MovieAVLTree* buckets[TABLE_SIZE]; // Array of AVL tree pointers

    // Hash function to determine the bucket index
    int hashFunction(int year) const;

public:
    // Constructor and Destructor
    MovieHashTable();
    ~MovieHashTable();

    // Methods to manipulate the hash table
    void insertMovie(const std::string& title,
                     const std::string& plot,
                     int year,
                     double rating,
                     const std::vector<std::tuple<std::string, std::string, std::string>>& actorDetails);

    MovieAVLNode* searchMovieByTitle(int year, const std::string& title) const;

    void addActorToMovie(int year,
                         const std::string& movieTitle,
                         const std::string& actorName,
                         const std::string& yearOfBirth,
                         const std::string& rating);

    void displayMoviesByYear(int recentYears) const;

    void displayActorsInMovie(int year, const std::string& movieTitle) const;
};

#endif // MOVIE_HASH_TABLE_H
