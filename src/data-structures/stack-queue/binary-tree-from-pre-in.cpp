//DONE
#include <stack>

#include "bst.h"

using namespace std;

Node* buildTree(int* preorder, int* inorder, int size) {
    // TODO
    if(size==0) return NULL;
    // Right of POSTORDER (LRN) is the ROOT of TREE
    int value = preorder[0];
    int index;
    // find index of value_right in inOrder
    for(int i = 0; i < size;i++){
        if(inorder[i] == value ){
            index = i;
            break;
        }
    }
    //Recursive to find all rest nodes.
    Node *p = new Node(value);
    //cal accurately to find left size and right size
    //ex : 0-1-2-3-|4|-5-6 , size = 7 -> left = index = 4 , right = size - index -1  = 7-4-1 =2
    //preorder + 1
    p->left = buildTree(preorder+1,inorder,(index+1)-1); 
    //right ez, just  + - 1 for accurate size. 
    p->right = buildTree(preorder + (index +1),inorder+(index+1),size - (index + 1));
    return p;
}

int main() {
    BinaryTreeForPractice binaryTree;

    int preorder[] = {10, 12, 7, 20, 30, 2, 9, 18,       15, 29, 4, 3, 6, 5};
    int inorder[] = {7, 12, 2, 30, 9, 20, 18,  10,       15, 4, 29, 6, 3, 5};
    int numOfNodes = sizeof(preorder) / sizeof(int);

    binaryTree.setRoot(buildTree(preorder, inorder, numOfNodes));
    binaryTree.preorder(print);
    binaryTree.inorder(print);
    binaryTree.levelOrder();

    return 0;
}
