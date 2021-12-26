//DONE
#include <stack>

#include "bst.h"

using namespace std;

void insert_rec(Node*& root, int value) {
    if (!root) {
        root = new Node(value);
        return;
    }
    if (root->key < value) {
        insert_rec(root->right, value);
    } else {
        insert_rec(root->left, value);
    }
}

Node* buildBSTFromPostorder(vector<int>& postOrder) {
    int size = postOrder.size() - 1;
    Node* newBST = nullptr;
    while (size >= 0) {
        insert_rec(newBST, postOrder[size]);
        size--;
    }
    return newBST;
}

int main() {
    BinaryTreeForPractice bst;

    vector<int> postOrder = {2, 4, 3, 8, 7, 10, 9, 6, 19, 18, 17, 21, 22, 20, 16, 15};
    bst.setRoot(buildBSTFromPostorder(postOrder));
    bst.inorder(print);
    bst.postorder(print);
    bst.levelOrder();

    return 0;
}
