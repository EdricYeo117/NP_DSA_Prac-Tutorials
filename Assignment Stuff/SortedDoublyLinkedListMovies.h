#ifndef SORTED_DOUBLY_LINKED_LIST_MOVIES_H
#define SORTED_DOUBLY_LINKED_LIST_MOVIES_H

#pragma once
#include <string>
#include <iostream>

using namespace std;

// Doubly Linked List Node for Movies
struct MovieNode {
    string movieTitle;
    string plot;         
    string yearOfRelease;
    double rating;
    MovieNode* prev;
    MovieNode* next;

    MovieNode(const string& title,
        const string& moviePlot,
        const string& year,
        double rate)
        : movieTitle(title), plot(moviePlot), yearOfRelease(year), rating(rate), prev(nullptr), next(nullptr) {}
};

// Sorted Doubly Linked List for Movies
class SortedDoublyLinkedListMovies {
public:
    SortedDoublyLinkedListMovies();
    ~SortedDoublyLinkedListMovies();

    void insertMovie(const string& title, const string& plot, const string& year, double rating);
    void displayMovies() const;
    MovieNode* getHead() const;

private:
    MovieNode* head;
    MovieNode* tail;

    void clear();
};

#endif // SORTED_DOUBLY_LINKED_LIST_MOVIES_H
