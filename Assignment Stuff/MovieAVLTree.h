#ifndef MOVIE_AVL_TREE_H
#define MOVIE_AVL_TREE_H

#include <string>
#include <vector>      
#include <tuple>       
#include "SortedDoublyLinkedListActors.h"
#pragma once

using namespace std;

// Movie AVL Tree Node
struct MovieAVLNode {
    string movieTitle;
    string plot;
    int yearOfRelease;
    double rating;
    int height;
    MovieAVLNode* left;
    MovieAVLNode* right;

    // Each node has a pointer to a sorted doubly linked list of actors
    SortedDoublyLinkedListActors* actors;

    MovieAVLNode(const string& title,
                 const string& moviePlot,
                 int year,
                 double rate)
        : movieTitle(title),
          plot(moviePlot),
          yearOfRelease(year),
          rating(rate),
          height(1),
          left(nullptr),
          right(nullptr),
          actors(new SortedDoublyLinkedListActors()) {}

    ~MovieAVLNode() {
        delete actors;
    }
};

// Movie AVL Tree
class MovieAVLTree {
public:
    MovieAVLTree();
    ~MovieAVLTree();

    // High-level operations
    void insertMovie(const string& title,
                     const string& plot,
                     int year,
                     double rating,
                     const vector<tuple<string,string,string>>& actorDetails);

    void addActorToMovie(const string& movieTitle,
                         const string& actorName,
                         const string& yearOfBirth,
                         const string& rating);

    void displayMoviesByYear(int recentYears) const;    
    void displayActorsInMovie(const string& movieTitle) const;
    MovieAVLNode* searchMovie(MovieAVLNode* node,
                              const string& title) const;
    MovieAVLNode* getRoot() const;

private:
    MovieAVLNode* root;

    // Recursive helpers
    MovieAVLNode* insertMovie(MovieAVLNode* node,
                              const string& title,
                              const string& plot,
                              int year,
                              double rating,
                              const vector<tuple<string,string,string>>& actorDetails);

    // AVL balancing
    MovieAVLNode* rotateLeft(MovieAVLNode* node);
    MovieAVLNode* rotateRight(MovieAVLNode* node);
    int getHeight(MovieAVLNode* node) const;
    int getBalanceFactor(MovieAVLNode* node) const;

    // In-order traversal for showing recent movies
    void inOrderTraversal(MovieAVLNode* node, int recentYears, bool& hasMovies) const;

    // Cleanup
    void clear(MovieAVLNode* node);
};

#endif // MOVIE_AVL_TREE_H
