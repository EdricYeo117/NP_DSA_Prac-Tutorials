#ifndef SORTED_DOUBLY_LINKED_LIST_ACTORS_H
#define SORTED_DOUBLY_LINKED_LIST_ACTORS_H

#pragma once
#include <string>
#include <iostream>

using namespace std;

// Doubly Linked List Node
struct ActorNode {
    string actorName;
    string yearOfBirth;
    string rating;
    ActorNode* prev;
    ActorNode* next;

    ActorNode(const string& name, 
              const string& yob = "", 
              const string& rate = "")
        : actorName(name),
          yearOfBirth(yob),
          rating(rate),
          prev(nullptr),
          next(nullptr) {}
};

// Sorted Doubly Linked List
class SortedDoublyLinkedListActors {
public:
    SortedDoublyLinkedListActors();
    ~SortedDoublyLinkedListActors();

    void insertActor(const string& actorName, 
                     const string& yearOfBirth, 
                     const string& rating);
    void displayActors() const;

    void updateActorInList(const std::string& currentName, const std::string& newName,
                                                     const std::string& newYearOfBirth, const std::string& newRating);

private:
    ActorNode* head;
    ActorNode* tail;

    void clear();
};

#endif // SORTED_DOUBLY_LINKED_LIST_ACTORS_H
