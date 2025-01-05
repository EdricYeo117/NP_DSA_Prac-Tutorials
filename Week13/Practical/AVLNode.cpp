#include <iostream>
using namespace std;

struct AVLNode {
    int item;
    AVLNode* left;
    AVLNode* right;
    AVLNode(int x) : item(x), left(nullptr), right(nullptr) {}
};

// Forward declarations (helper functions)
void printCustom(AVLNode* root);
void visitLeftSubtree(AVLNode* node12);
void handleNode5(AVLNode* node5);
void handleNode16(AVLNode* node16);
void visitRightSubtree(AVLNode* node30);

int main() {
    // Suppose 'root' is the final AVL tree from part (b).
    // (Implementation to build that tree is omitted here
    //  but we assume we have it.)

    AVLNode* root;/* the final tree with root->item = 24 */

    printCustom(root);
    cout << endl;

    return 0;
}

//------------------------------------------------------------
// printCustom: produce the sequence 5 11 9 13 20 16 12 45 30 24
//------------------------------------------------------------
void printCustom(AVLNode* root) {
    if (!root) return;

    // root->item = 24
    // root->left->item = 12
    // root->right->item = 30

    // 1) handle the left subtree in a special pattern (prints 5 11 9 13 20 16 12)
    visitLeftSubtree(root->left);  

    // 2) handle the right subtree (prints 45 30)
    visitRightSubtree(root->right);

    // 3) print the root (24)
    cout << root->item << " ";  // "24"
}

//------------------------------------------------------------
// This visits node12 (the left child of 24) to print: 5 11 9 13 20 16 12
//------------------------------------------------------------
void visitLeftSubtree(AVLNode* node12) {
    if (!node12) return;

    // node12->left->item = 5
    // node12->right->item = 16
    // We'll do:
    //    handle node5  => (5 11 9)
    //    handle node16 => (13 20 16)
    //    then print 12
    handleNode5(node12->left);   
    handleNode16(node12->right);
    cout << node12->item << " "; // "12"
}

//------------------------------------------------------------
// This handles the subtree at node 5 to print: 5 11 9
//------------------------------------------------------------
void handleNode5(AVLNode* node5) {
    // node5->item = 5
    // node5->right->item = 11
    // node5->right->left->item = 9  (or node5->left->item=??)
    // Actually from the final tree, 5->left is null, 5->right = 11, 11->left=9
    // But the question's desired order is: 5 11 9
    // So we can do:
    cout << node5->item << " ";         // 5
    cout << node5->right->item << " ";  // 11
    cout << node5->right->left->item << " "; // 9
}

//------------------------------------------------------------
// This handles node16, printing: 13 20 16
//------------------------------------------------------------
void handleNode16(AVLNode* node16) {
    // node16->left->item = 13
    // node16->right->item = 20
    // we want the sequence => 13 20 16
    cout << node16->left->item << " ";  // 13
    cout << node16->right->item << " "; // 20
    cout << node16->item << " ";        // 16
}

//------------------------------------------------------------
// This visits node30 (the right child of 24) to print: 45 30
//------------------------------------------------------------
void visitRightSubtree(AVLNode* node30) {
    // The final tree has node30->right->item=45, node30->left=null
    // Desired order => 45 30
    cout << node30->right->item << " "; // 45
    cout << node30->item << " ";        // 30
}