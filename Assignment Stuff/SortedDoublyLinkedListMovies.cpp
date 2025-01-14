#include "SortedDoublyLinkedListMovies.h"

SortedDoublyLinkedListMovies::SortedDoublyLinkedListMovies() : head(nullptr), tail(nullptr) {}

SortedDoublyLinkedListMovies::~SortedDoublyLinkedListMovies() {
    clear();
}

void SortedDoublyLinkedListMovies::insertMovie(const string& title,
    const string& plot,
    const string& year,
    double rating) {
    MovieNode* newNode = new MovieNode(title, plot, year, rating);

    // If the list is empty
    if (!head) {
        head = tail = newNode;
        return;
    }

    // Insert at the beginning if lexicographically smaller
    if (title < head->movieTitle) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    // Find the correct position in ascending order by title
    MovieNode* current = head;
    while (current->next && current->next->movieTitle < title) {
        current = current->next;
    }

    // Insert after `current`
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next) {
        current->next->prev = newNode;
    }
    else {
        tail = newNode;  // Update tail if inserted at the end
    }

    current->next = newNode;
}

void SortedDoublyLinkedListMovies::displayMovies() const {
    MovieNode* current = head;
    while (current) {
        cout << "Movie: " << current->movieTitle
            << " | Plot: " << current->plot
            << " | Year: " << current->yearOfRelease
            << " | Rating: " << current->rating;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

void SortedDoublyLinkedListMovies::clear() {
    MovieNode* current = head;
    while (current) {
        MovieNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = tail = nullptr;
}
