#include "BST.h"
#include <algorithm> 
using namespace std;

int BST::countNodes() {
    return countNodes(root);
}


int BST::countNodes(BinaryNode* t) {
    if (t == nullptr) {
        return 0;
    }
    return 1 + countNodes(t->left) + countNodes(t->right);
}

int BST::getHeight() {
    return getHeight(root);
}

// Private helper
int BST::getHeight(BinaryNode* t) {
    if (t == nullptr) {
        // Convention: height of an empty subtree = 0
        return 0;
    }
    int leftHeight = getHeight(t->left);
    int rightHeight = getHeight(t->right);

    return 1 + max(leftHeight, rightHeight);
}

bool BST::isBalanced() {
    return isBalanced(root);
}

bool BST::isBalanced(BinaryNode* t) {
    if (t == nullptr) {
        // An empty tree is balanced
        return true;
    }

    int leftHeight = getHeight(t->left);
    int rightHeight = getHeight(t->right);

    // Check current node balance factor
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }

    // Recursively check left and right subtrees
    return isBalanced(t->left) && isBalanced(t->right);
}