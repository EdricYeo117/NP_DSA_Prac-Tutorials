#include "MovieAVLTree.h"
#include <iostream>
#include <ctime>
#include <tuple>
#include <algorithm>

using namespace std;

MovieAVLTree::MovieAVLTree() : root(nullptr) {}

MovieAVLTree::~MovieAVLTree()
{
    clear(root);
}

// Insert a movie with its details and actors
void MovieAVLTree::insertMovie(const string& title,
    const string& plot,
    int year,
    double rating,
    const vector<tuple<string, string, string>>& actorDetails)
{
    root = insertMovie(root, title, plot, year, rating, actorDetails);
}

// Recursive helper for inserting a movie (BST + AVL balancing)
MovieAVLNode* MovieAVLTree::insertMovie(MovieAVLNode* node,
    const string& title,
    const string& plot,
    int year,
    double rating,
    const vector<tuple<string, string, string>>& actorDetails)
{
    // Standard BST insertion
    if (!node) {
        // Create a new node, add the actors
        MovieAVLNode* newNode = new MovieAVLNode(title, plot, year, rating);
        // Insert all the actor details into this node's doubly linked list
        for (auto& actorInfo : actorDetails) {
            // actorInfo is a tuple<string actorName, string yearOfBirth, string rating>
            string actorName, actorYOB, actorRating;
            tie(actorName, actorYOB, actorRating) = actorInfo;
            newNode->actors->insertActor(actorName, actorYOB, actorRating);
        }
        return newNode;
    }

    // Compare titles to decide left or right
    if (title < node->movieTitle) {
        node->left = insertMovie(node->left, title, plot, year, rating, actorDetails);
    }
    else if (title > node->movieTitle) {
        node->right = insertMovie(node->right, title, plot, year, rating, actorDetails);
    }
    else {
        // If the movie title already exists, you might decide to update or ignore
        // For simplicity, we'll do nothing here
        return node;
    }

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get the balance factor
    int balance = getBalanceFactor(node);

    /*
    AWL Balancing Cases
    */

    // Left-Heavy: Left Left Case
    if (balance > 1 && title < node->left->movieTitle) {
        return rotateRight(node);
    }
    // Right-Heavy: Right Right Case
    if (balance < -1 && title > node->right->movieTitle) {
        return rotateLeft(node);
    }
    // Left-Right Case
    if (balance > 1 && title > node->left->movieTitle) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // Right-Left Case
    if (balance < -1 && title < node->right->movieTitle) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // Return the (possibly rotated) node pointer
    return node;
}

// Public function to add one actor to an existing movie
void MovieAVLTree::addActorToMovie(const string& movieTitle,
    const string& actorName,
    const string& yearOfBirth,
    const string& rating)
{
    // Find the node for that movie
    MovieAVLNode* found = searchMovie(root, movieTitle);
    if (found) {
        found->actors->insertActor(actorName, yearOfBirth, rating);
    }
    else {
        cerr << "Movie \"" << movieTitle << "\" not found.\n";
    }
}

// Public function to display movies made within the past 'recentYears' years
void MovieAVLTree::displayMoviesByYear(int recentYears) const {
    // Calculate the minimum year for filtering
    time_t now = time(nullptr);
    tm localTime;
    localtime_s(&localTime, &now); // Use localtime_s instead of localtime
    int currentYear = 1900 + localTime.tm_year;
    int minYear = currentYear - recentYears;

    // Track whether any movies are displayed
    bool hasMovies = false;

    cout << "Movies released in the last " << recentYears << " years:\n";

    // Perform in-order traversal
    inOrderTraversal(root, minYear, hasMovies);

    // If no movies were found, display a message
    if (!hasMovies) {
        cout << "No movies found released in the last " << recentYears << " years.\n";
    }
}

// Public function to display all actors in a given movie
void MovieAVLTree::displayActorsInMovie(const string& movieTitle) const {
    MovieAVLNode* found = searchMovie(root, movieTitle);
    if (found) {
        cout << "Actors in movie \"" << movieTitle << "\": ";
        found->actors->displayActors();
    }
    else {
        cerr << "Movie \"" << movieTitle << "\" not found.\n";
    }
}

// ------------------ PRIVATE HELPER FUNCTIONS ------------------

// Search for a movie node by title
MovieAVLNode* MovieAVLTree::searchMovie(MovieAVLNode* node, const string& title) const {
    if (!node) return nullptr;
    if (title == node->movieTitle) return node;
    if (title < node->movieTitle) return searchMovie(node->left, title);
    else return searchMovie(node->right, title);
}

// Left rotation
MovieAVLNode* MovieAVLTree::rotateLeft(MovieAVLNode* node) {
    MovieAVLNode* newRoot = node->right;
    MovieAVLNode* transferSubtree = newRoot->left;

    newRoot->left = node;
    node->right = transferSubtree;

    // Update heights
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

// Right rotation
MovieAVLNode* MovieAVLTree::rotateRight(MovieAVLNode* node) {
    MovieAVLNode* newRoot = node->left;
    MovieAVLNode* transferSubtree = newRoot->right;

    newRoot->right = node;
    node->left = transferSubtree;

    // Update heights
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

// Get node height safely
int MovieAVLTree::getHeight(MovieAVLNode* node) const {
    if (!node) return 0;
    return node->height;
}

// Compute balance factor
int MovieAVLTree::getBalanceFactor(MovieAVLNode* node) const {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Get root node
MovieAVLNode* MovieAVLTree::getRoot() const {
	return root;
}

// In-order traversal that only prints movies released after (or equal to) minYear
void MovieAVLTree::inOrderTraversal(MovieAVLNode* node, int minYear, bool& hasMovies) const {
    if (!node) return;

    // Recursive call on the left subtree
    inOrderTraversal(node->left, minYear, hasMovies);

    // Print movie details if yearOfRelease >= minYear
    if (node->yearOfRelease >= minYear) {
        hasMovies = true; // Set flag to true as we found at least one movie
        cout << "Title: " << node->movieTitle
            << " | Year: " << node->yearOfRelease
            << " | Rating: " << node->rating
            << " | Plot: " << node->plot << endl;
    }

    // Recursive call on the right subtree
    inOrderTraversal(node->right, minYear, hasMovies);
}

// Recursively clear the tree
void MovieAVLTree::clear(MovieAVLNode* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;  // This will also delete the `actors` list in the MovieAVLNode destructor
}