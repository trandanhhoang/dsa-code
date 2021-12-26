//DONE
#include <stack>

#include "bst.h"

using namespace std;
//RESEARCH

Node* buildTree(int* postorder, int* inorder, int size) {
    // TODO
    if (size == 0) return NULL;
    // Right of POSTORDER (LRN) is the ROOT of TREE
    int value = postorder[size - 1];
    int index;
    // find index of value_right in inOrder
    for (int i = 0; i < size; i++) {
        if (inorder[i] == value) {
            index = i;
            break;
        }
    }
    //Recursive to find all rest nodes.
    Node* p = new Node(value);
    //cal accurately to find left size and right size
    //ex : 0-1-2-3-|4|-5-6 , size = 7 -> left = index = 4 , right = size - index -1  = 7-4-1 =2
    p->left = buildTree(postorder, inorder, index);
    //inorder - head (2), post order - last(3)
    p->right = buildTree(postorder + index, inorder + index + 1, size - index - 1);
    return p;
}



// Postorder: 7 2 9 30 18 20 12 4 6 5 3 29 15 10
// Inorder: 7 12 2 30 9 20 18 10 15 4 29 6 3 5
// Level order: 10 12 15 7 20 29 30 18 4 3 2 9 6 5

int main() {
    BinaryTreeForPractice binaryTree;

    int postorder[] = {7, 2, 9, 30, 18, 20, 12, 4, 6, 5, 3, 29, 15, 10};
    int inorder[] = {7, 12, 2, 30, 9, 20, 18, 10, 15, 4, 29, 6, 3, 5};
    int numOfNodes = sizeof(postorder) / sizeof(int);

    binaryTree.setRoot(buildTree(postorder, inorder, numOfNodes));
    binaryTree.postorder(print);
    binaryTree.inorder(print);
    binaryTree.levelOrder();

    return 0;
}

/*

    if (size == 0) return nullptr;
    Node* newTree = new Node(postorder[size - 1]);
    int middle;
    for (middle = 0; middle < size; middle++) {
        if (inorder[middle] == postorder[size - 1]) {
            break;
        }
    }
    int newSizeLeft = middle;
    int newSizeRight = size - middle - 1;
    newTree->left = buildTree(postorder, inorder, newSizeLeft);
    newTree->right = buildTree(postorder + middle, inorder + middle + 1, newSizeRight);
    return newTree;*/
