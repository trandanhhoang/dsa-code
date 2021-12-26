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

Node* buildBSTFromPreorder(vector<int>& preorder) {
    // TODO
    Node* p = nullptr;
    int index = 0;
    while (index < preorder.size()) {
        insert_rec(p, preorder[index]);
        index++;
    }

    return p;
}

int main() {
    BinaryTreeForPractice bst;

    vector<int> preorder = {15, 6, 3, 2, 4, 9, 7, 8, 10, 16, 20, 17, 18, 19, 22, 21};
    bst.setRoot(buildBSTFromPreorder(preorder));
    bst.inorder(print);
    bst.preorder(print);
    bst.levelOrder();

    return 0;
}
