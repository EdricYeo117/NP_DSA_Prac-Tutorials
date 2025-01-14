#ifndef ACTIR_AVL_TREE_H
#define ACTOR_AVL_TREE_H

#include <string>
#include <vector>      
#include <tuple>       
#include "SortedDoublyLinkedListMovies.h"
#pragma once

using namespace std;

// Actor AVL Node
struct ActorAVLNode {
    string actorName;
    string yearOfBirth; 
    string rating;      
    int height;
    SortedDoublyLinkedListMovies* movies;
    ActorAVLNode* left;
    ActorAVLNode* right;

    ActorAVLNode(const string& name, const string& yob, const string& actorRating)
        : actorName(name), yearOfBirth(yob), rating(actorRating), height(1),
        movies(new SortedDoublyLinkedListMovies()), left(nullptr), right(nullptr) {}

    ~ActorAVLNode() {
        delete movies;
    }
};

// AVL Tree for Actors
class ActorAVLTree {
public:
    ActorAVLTree();
    ~ActorAVLTree();

    // High-level operations
    void insertActor(const string& name,
        const string& yearOfBirth,
        const string& rating,
        const string& movieTitle,
        const string& moviePlot,
        const string& movieYear,
        double movieRating);

    void displayActors() const;

    void findActorsByYearOfBirth(const string& yearOfBirth, vector<string>& actorNames) const;
	void findActorsByYearOfBirth(ActorAVLNode* node, const string& yearOfBirth, vector<string>& actorNames) const;
    ActorAVLNode* searchActor(const string& actorName) const;

private:
    ActorAVLNode* root;

    // Recursive helpers
    ActorAVLNode* insertActor(ActorAVLNode* node,
        const string& name,
        const string& yearOfBirth,
        const string& rating,
        const string& movieTitle,
        const string& moviePlot,
        const string& movieYear,
        double movieRating);

    void displayInOrder(ActorAVLNode* node) const;

    // AVL balancing
    ActorAVLNode* rotateLeft(ActorAVLNode* node);
    ActorAVLNode* rotateRight(ActorAVLNode* node);
    int getHeight(ActorAVLNode* node) const;
    int getBalanceFactor(ActorAVLNode* node) const;

    // Cleanup
    void clear(ActorAVLNode* node);
};

#endif // ACTOR_AVL_TREE_H