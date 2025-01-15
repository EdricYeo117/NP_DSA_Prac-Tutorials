#include "ActorHashTable.h"
#include <iostream>

using namespace std;

ActorHashTable::ActorHashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        buckets[i] = new ActorAVLTree();
    }
}

ActorHashTable::~ActorHashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        delete buckets[i];
    }
}

int ActorHashTable::getSize() const {
    return TABLE_SIZE;
}


int ActorHashTable::hashFunction(const string& yearOfBirth) const {
    try {
        int year = stoi(yearOfBirth); // Convert year of birth to an integer
        return abs(year % TABLE_SIZE); // Ensure non-negative index
    }
    catch (const invalid_argument&) {
        cerr << "Invalid year of birth: " << yearOfBirth << endl;
        return 0; // Default to first bucket
    }
}

void ActorHashTable::insertActor(const string& name,
    const string& yearOfBirth,
    const string& rating,
    const string& movieTitle,
    const string& moviePlot,
    const string& movieYear,
    double movieRating) {
    int bucketIndex = hashFunction(yearOfBirth);
    buckets[bucketIndex]->insertActor(name, yearOfBirth, rating, movieTitle, moviePlot, movieYear, movieRating);
}

void ActorHashTable::displayActorsByYearRange(const string& minYear, const string& maxYear) const {
    bool hasActors = false;
    int minBucket = hashFunction(minYear);
    int maxBucket = hashFunction(maxYear);

    for (int i = minBucket; i <= maxBucket; ++i) {
        if (buckets[i]) {
            if (!hasActors) {
                cout << "Actors born between " << minYear << " and " << maxYear << ":\n";
                hasActors = true;
            }
            buckets[i]->displayActors();
        }
    }
    if (!hasActors) {
        cout << "No actors found between " << minYear << " and " << maxYear << ".\n";
    }
}


void ActorHashTable::displayAllActors() const {
    bool hasActors = false;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (buckets[i]) {
            if (!hasActors) {
                cout << "All actors in the hash table:\n";
                hasActors = true;
            }
            buckets[i]->displayActors();
        }
    }
    if (!hasActors) {
        cout << "No actors found in the hash table.\n";
    }
}

ActorAVLTree* ActorHashTable::getBucket(int index) const {
    if (index < 0 || index >= TABLE_SIZE) return nullptr;
    return buckets[index];
}

