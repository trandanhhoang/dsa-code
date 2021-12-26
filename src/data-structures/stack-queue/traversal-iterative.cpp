#include <iostream>
#include <stack>
#include <vector>

#include "my-lib.h"
using namespace std;
#include <unordered_map>

#include "bst.h"

using namespace std;
// vector<int> preorder = {15, 6, 3, 2, 4, 9, 7, 8, 10, 16, 20, 17, 18, 19, 22, 21};
void preorderIterative(Node *root) {  //NLR
    cout << "Preorder: ";

    stack<Node *> preOrderStack;
    preOrderStack.push(root);
    while (!preOrderStack.empty()) {
        Node *pCurrent = preOrderStack.top();
        preOrderStack.pop();
        cout << pCurrent->key << " ";
        if (pCurrent->right) {
            preOrderStack.push(pCurrent->right);
        }
        if (pCurrent->left) {
            preOrderStack.push(pCurrent->left);
        }
    }
    cout << "\n";
}

void inorderIterative2(Node *root) {  //LNR
    cout << "Inorder: ";
    stack<Node *> my_stack;
    vector<int> my_sort;
    my_stack.push(root);
    my_sort.push_back(root->key);
    while (!my_stack.empty()) {
        Node *top = my_stack.top();
        my_stack.pop();
        if (top->left) {
            my_stack.push(top->left);
            my_sort.push_back(top->left->key);
        }
        if (top->right) {
            my_stack.push(top->right);
            my_sort.push_back(top->right->key);
        }
    }
    sort(my_sort.begin(), my_sort.end());
    for (int i = 0; i < my_sort.size(); i++) {
        cout << my_sort[i] << " ";
    }
    cout << "\n";
}

void inorderIterative(Node *root) {  //LNR
    cout << "Inorder: ";
    stack<Node *> inOrderStack;
    while (root) {
        inOrderStack.push(root);
        root = root->left;
    }
    while (!inOrderStack.empty()) {
        Node *top = inOrderStack.top();
        inOrderStack.pop();
        cout << top->key << " ";
        if (top->right) {
            Node *run = top->right;
            while (run) {
                inOrderStack.push(run);
                run = run->left;
            }
        }
    }

    cout << "\n";
}

            // 5
        //   /  \
        // 2     6
    //   /  \     \
    // 1     4     7
        // /
    //   3

    //1-3-4-2-7-6-5
    //5 , |2,       |5,6,7,2
    //2   |5,2,1      |6,4

void postorderIterative(Node *root) {  //LRN
    cout << "Postorder: ";
    stack<Node *> firstStack;
    stack<Node *> secondStack;
    
    cout << "\n";
}

int main() {
    BinaryTreeForPractice bst;

    vector<int> preorder = {15, 6, 3, 2, 4, 9, 7, 8, 10, 16, 20, 17, 18, 19, 22, 21};
    for (auto &&ele : preorder) {
        bst.insert(ele);
    }
    auto root = bst.getRoot();

    // Preorder
    bst.preorder(print);
    preorderIterative(root);
    cout << "\n";

    // Inorder
    bst.inorder(print);
    inorderIterative2(root);
    cout << "\n";

    // Postorder
    bst.postorder(print);
    postorderIterative(root);
    cout << "\n";

    return 0;
}

/*
    stack<Node *> node_stack, child_stack;
    node_stack.push(root);
    while (!node_stack.empty()) {
        Node *top = node_stack.top();
        child_stack.push(top);
        node_stack.pop();
        if (top->left)
            node_stack.push(top->left);
        if (top->right)
            node_stack.push(top->right);
    }
    while (!child_stack.empty()) {
        cout << child_stack.top()->key << " ";
        child_stack.pop();
    }
*/
