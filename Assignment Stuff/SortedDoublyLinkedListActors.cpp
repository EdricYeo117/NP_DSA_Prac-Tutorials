#include "SortedDoublyLinkedListActors.h"

// Constructor
SortedDoublyLinkedListActors::SortedDoublyLinkedListActors()
    : head(nullptr), tail(nullptr) {}

// Destructor
SortedDoublyLinkedListActors::~SortedDoublyLinkedListActors() {
    clear();
}

// Insert an actor into the sorted list (by actorName)
void SortedDoublyLinkedListActors::insertActor(
    const string& actorName, 
    const string& yearOfBirth, 
    const string& rating
) {
    ActorNode* newNode = new ActorNode(actorName, yearOfBirth, rating);

    // If the list is empty
    if (!head) {
        head = tail = newNode;
        return;
    }

    // Insert at the beginning if it's lexicographically smaller
    if (actorName < head->actorName) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    // Otherwise, find the correct position in ascending (lexicographic) order
    ActorNode* current = head;
    while (current->next && current->next->actorName < actorName) {
        current = current->next;
    }

    // Insert after 'current'
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next) {
        current->next->prev = newNode;
    } else {
        tail = newNode;  // If inserted at the end, update tail
    }

    current->next = newNode;
}

// Display all actors in the list
void SortedDoublyLinkedListActors::displayActors() const {
    ActorNode* current = head;
    while (current) {
        cout << "Actor: " << current->actorName
             << ", Year: " << current->yearOfBirth
             << ", Rating: " << current->rating;
        if (current->next) cout << "  ->  ";
        current = current->next;
    }
    cout << endl;
}

void SortedDoublyLinkedListActors::updateActorInList(const std::string& currentName, const std::string& newName,
                                                     const std::string& newYearOfBirth, const std::string& newRating) {
    ActorNode* current = head;

    while (current) {
        if (current->actorName == currentName) {
            // Update actor details
            current->actorName = newName;
            current->yearOfBirth = newYearOfBirth;
            current->rating = newRating;
            return;
        }
        current = current->next;
    }

    std::cout << "Actor not found in the movie's actor list.\n";
}


// Clear the entire list
void SortedDoublyLinkedListActors::clear() {
    ActorNode* current = head;
    while (current) {
        ActorNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = tail = nullptr;
}
