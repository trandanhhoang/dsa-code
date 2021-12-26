#include "avl.h"

#include <iostream>

using namespace std;

int main() {
    AVL *root = NULL;
    //1 0 -1 9 5 2 6 11
    /* Constructing tree given in
    the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    preOrder(root);
    cout << "\n";
    root = deleteNode(root, 10);
    preOrder(root);
    return 1;
}
