#ifndef ACTOR_HASH_TABLE_H
#define ACTOR_HASH_TABLE_H

#include "ActorAVLTree.h"
#include <string>

using namespace std;

// Hash Table for Actors
class ActorHashTable {
private:
    static const int TABLE_SIZE = 101; // Number of buckets in the hash table
    ActorAVLTree* buckets[TABLE_SIZE];

    // Hash function to map year of birth to a bucket
    int hashFunction(const string& yearOfBirth) const;

public:
    ActorHashTable();
    ~ActorHashTable();

    // Methods to interact with the hash table
    void insertActor(const string& name,
        const string& yearOfBirth,
        const string& rating,
        const string& movieTitle,
        const string& moviePlot,
        const string& movieYear,
        double movieRating);

    void displayActorsByYearRange(const string& minYear, const string& maxYear) const;
    void displayAllActors() const;
    ActorAVLTree* getBucket(int index) const;
};

#endif // ACTOR_HASH_TABLE_H
