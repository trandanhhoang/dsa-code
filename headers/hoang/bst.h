#if !defined(BST_H)
#define BST_H

#include <iostream>
#include <queue>

struct Node {
    int key;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int key) : key(key) {}
};

class BST {
   protected:
    Node *root = nullptr;

   public:
    ~BST();

    /* Basic operations */
    bool search(int value);
    void insert(int value);
    void remove(int value);

    /* Utils */
    int findMin();
    int findMax();
    int countNodes();
    int countLeafNodes();
    int getHeight();

    /* Traversal */
    void preorder();
    void inorder();
    void postorder();
    void levelOrder();
};

/* Public */

BST::~BST() {
    // TODO
}

bool BST::search(int value) {
    // TODO
}

void BST::insert(int value) {
    // TODO
}

void BST::remove(int value) {
    // TODO
}

int BST::findMin() {
    if (!this->root) {
        throw "Tree is empty!";
    }
    // TODO
}

int BST::findMax() {
    if (!this->root) {
        throw "Tree is empty!";
    }
    // TODO
}

int BST::countNodes() {
    // TODO
}

int BST::countLeafNodes() {
    // TODO
}

int BST::getHeight() {
    // TODO
}

void BST::preorder() {
    std::cout << "Preorder: ";
    // TODO
    std::cout << "\n";
}

void BST::inorder() {
    std::cout << "Inorder: ";
    // TODO
    std::cout << "\n";
}

void BST::postorder() {
    std::cout << "Postorder: ";
    // TODO
    std::cout << "\n";
}

void BST::levelOrder() {
    std::cout << "Level order:\n";
    // TODO
}

/* This class is for practicing */

class BinaryTreeForPractice : public BST {
   public:
    Node *getRoot() { return root; }
    void setRoot(Node *root) { this->root = root; }
};

#endif  // BST_H
