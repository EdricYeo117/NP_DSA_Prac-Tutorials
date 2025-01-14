#include "ActorAVLTree.h"
#include <iostream>
#include <algorithm>
#include <ctime> 

using namespace std;

ActorAVLTree::ActorAVLTree() : root(nullptr) {}

ActorAVLTree::~ActorAVLTree() {
    clear(root);
}

void ActorAVLTree::insertActor(const string& name,
    const string& yearOfBirth,
    const string& rating,
    const string& movieTitle,
    const string& moviePlot,
    const string& movieYear,
    double movieRating) {
    root = insertActor(root, name, yearOfBirth, rating, movieTitle, moviePlot, movieYear, movieRating);
}

ActorAVLNode* ActorAVLTree::insertActor(ActorAVLNode* node,
    const string& name,
    const string& yearOfBirth,
    const string& rating,
    const string& movieTitle,
    const string& moviePlot,
    const string& movieYear,
    double movieRating) {
    // Standard BST insertion
    if (!node) {
        ActorAVLNode* newNode = new ActorAVLNode(name, yearOfBirth, rating);
        newNode->movies->insertMovie(movieTitle, moviePlot, movieYear, movieRating);
        return newNode;
    }

    // Insert based on actor name
    if (name < node->actorName) {
        node->left = insertActor(node->left, name, yearOfBirth, rating, movieTitle, moviePlot, movieYear, movieRating);
    }
    else if (name > node->actorName) {
        node->right = insertActor(node->right, name, yearOfBirth, rating, movieTitle, moviePlot, movieYear, movieRating);
    }
    else {
        // If actor exists, add movie to their list
        node->movies->insertMovie(movieTitle, moviePlot, movieYear, movieRating);
        return node; // No rebalancing needed
    }

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Balance the node
    int balance = getBalanceFactor(node);

    // Left heavy
    if (balance > 1 && name < node->left->actorName) {
        return rotateRight(node);
    }
    // Right heavy
    if (balance < -1 && name > node->right->actorName) {
        return rotateLeft(node);
    }
    // Left-Right case
    if (balance > 1 && name > node->left->actorName) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // Right-Left case
    if (balance < -1 && name < node->right->actorName) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void ActorAVLTree::findActorsByYearOfBirth(const string& yearOfBirth, vector<string>& actorNames) const {
    findActorsByYearOfBirth(root, yearOfBirth, actorNames);
}

void ActorAVLTree::findActorsByYearOfBirth(ActorAVLNode* node, const string& yearOfBirth, vector<string>& actorNames) const {
    if (!node) return;

    // Perform an in-order traversal
    findActorsByYearOfBirth(node->left, yearOfBirth, actorNames);
    if (node->yearOfBirth == yearOfBirth) {
        actorNames.push_back(node->actorName); // Add actor's name to the list
    }
    findActorsByYearOfBirth(node->right, yearOfBirth, actorNames);
}

void ActorAVLTree::displayActors() const {
    displayInOrder(root);
}

void ActorAVLTree::displayInOrder(ActorAVLNode* node) const {
    if (!node) return;

    displayInOrder(node->left);

    // Calculate age dynamically
    time_t now = time(nullptr);
    tm localTime;
    localtime_s(&localTime, &now);
    int currentYear = 1900 + localTime.tm_year;
    int age = currentYear - stoi(node->yearOfBirth);

    cout << "Actor: " << node->actorName
        << " | Year of Birth: " << node->yearOfBirth
        << " | Age: " << age
        << " | Rating: " << node->rating
        << "\nMovies:\n";
    node->movies->displayMovies();
    cout << endl;

    displayInOrder(node->right);
}

ActorAVLNode* ActorAVLTree::searchActor(const string& actorName) const {
    ActorAVLNode* current = root;
    while (current) {
        if (actorName == current->actorName) {
            return current; // Actor found
        }
        else if (actorName < current->actorName) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return nullptr; // Actor not found
}

// ------------------ AVL Balancing ------------------

ActorAVLNode* ActorAVLTree::rotateLeft(ActorAVLNode* node) {
    ActorAVLNode* newRoot = node->right;
    ActorAVLNode* transferSubtree = newRoot->left;

    newRoot->left = node;
    node->right = transferSubtree;

    // Update heights
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

ActorAVLNode* ActorAVLTree::rotateRight(ActorAVLNode* node) {
    ActorAVLNode* newRoot = node->left;
    ActorAVLNode* transferSubtree = newRoot->right;

    newRoot->right = node;
    node->left = transferSubtree;

    // Update heights
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

int ActorAVLTree::getHeight(ActorAVLNode* node) const {
    if (!node) return 0;
    return node->height;
}

int ActorAVLTree::getBalanceFactor(ActorAVLNode* node) const {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// ------------------ Cleanup ------------------

void ActorAVLTree::clear(ActorAVLNode* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}
