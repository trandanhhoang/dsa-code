#if !defined(BST_H)
#define BST_H

#include <iostream>
#include <queue>

using namespace std;

void print(int n) {
    cout << n << " ";
}

struct Node {
    int key;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int key) : key(key) {}
};

class BST {
   protected:
    Node *root = nullptr;

    bool search_rec(Node *root, int value);
    void insert_rec(Node *&root, int value);
    void remove_rec(Node *&root, int value);

    void preorder_rec(Node *, void (*f)(int));
    void inorder_rec(Node *root, void (*f)(int));
    void postorder_rec(Node *, void (*f)(int));
    // void levelOrder_rec(Node *,void);

    int findMin_rec(Node *);
    int findMax_rec(Node *);
    int countNodes_rec(Node *);
    int countLeafNodes_rec(Node *);
    int getHeight_rec(Node *);

   public:
    ~BST();

    /* Basic operations */
    bool search(int value);
    void insert(int value);
    void insertIte(int value);
    void remove(int value);

    /* Utils */
    int findMin();
    int findMax();
    int countNodes();
    int countLeafNodes();
    int getHeight();

    /* Traversal */
    void preorder(void (*f)(int));
    void inorder(void (*f)(int));
    void postorder(void (*f)(int));
    void levelOrder(void);
};

/* Public */

BST::~BST() {
    // TODO
    delete root;
    root = nullptr;
}

bool BST::search(int value) {
    // TODO
    Node *p = root;
    while (p) {
        if (p->key == value)
            return 1;
        else if (p->key < value)
            p = p->right;
        else
            p = p->left;
    }
    return 0;
}

void BST::insertIte(int value) {
    // TODO
    Node *p = new Node(value);
    if (root == nullptr) {
        root = p;
        return;
    }
    Node *pCr = root;
    while (pCr != NULL) {
        if (pCr->key >= value) {
            if (pCr->left == NULL) {
                pCr->left = p;
                break;
            }
            pCr = pCr->left;
        } else if (pCr->key < value) {
            if (pCr->right == NULL) {
                pCr->right = p;
                break;
            }
            pCr = pCr->right;
        }
    }
}

void BST::insert(int value) {
    insert_rec(root, value);
}
void BST::insert_rec(Node *&root, int value) {
    if (root == NULL) {
        root = new Node(value);
        return;
    }
    if (root->key <= value) {
        insert_rec(root->right, value);
    }
    if (root->key > value) {
        insert_rec(root->left, value);
    }
}

void BST::remove(int value) {
    // TODO
    remove_rec(root, value);
}

void BST::remove_rec(Node *&root, int value) {
    // TODO
    if (root->key == value) {
        // case 1 : null 1 side -> change ROOT
        if (!root->left) {
            root = root->right;
        } else {
            Node *p = root->left;
            while (p->right) {
                p = p->right;
            }
            root->key = p->key;
            remove_rec(root->left, p->key);
        }
    } else if (root->key < value) {
        remove_rec(root->right, value);
    } else {
        remove_rec(root->left, value);
    }
}

int BST::findMin() {
    if (!this->root) {
        throw "Tree is empty!";
    }
    // TODO
    Node *p = root;
    Node *walker = p;
    while (p) {
        walker = p;
        p = p->left;
    }
    return walker->key;
}

int BST::findMax() {
    if (!this->root) {
        throw "Tree is empty!";
    }
    // TODO
    Node *p = root;
    Node *walker = p;
    while (p) {
        walker = p;
        p = p->right;
    }
    return walker->key;
}

int BST::countNodes() {
    // TODO
    return countNodes_rec(root);
}

int BST::countNodes_rec(Node *p) {
    // TODO
    if (!p) return 0;
    return 1 + countNodes_rec(p->left) + countNodes_rec(p->right);
}

int BST::countLeafNodes() {
    // TODO
    return countLeafNodes_rec(root);
}

int BST::countLeafNodes_rec(Node *p) {
    // TODO
    if (!p) return 0;
    if (!p->left && !p->right) return 1;
    return 0 + countLeafNodes_rec(p->left) + countLeafNodes_rec(p->right);
}

int BST::getHeight() {
    // TODO
    return getHeight_rec(root);
}

int BST::getHeight_rec(Node *p) {
    // TODO
    if (!p) return 0;

    int left_h = getHeight_rec(p->left);
    int right_h = getHeight_rec(p->right);

    return 1 + max<int>(left_h, right_h);
}

void BST::preorder_rec(Node *root, void (*print)(int)) {
    if (root == nullptr) return;
    print(root->key);
    preorder_rec(root->left, print);
    preorder_rec(root->right, print);
}

void BST::preorder(void (*print)(int)) {
    std::cout << "Preorder: ";
    // TODO
    preorder_rec(root, print);
    std::cout << "\n";
}

void BST::inorder_rec(Node *root, void (*print)(int)) {
    if (root == nullptr) return;
    inorder_rec(root->left, print);
    print(root->key);
    inorder_rec(root->right, print);
}

void BST::inorder(void (*print)(int)) {
    std::cout << "Inorder: ";
    // TODO
    inorder_rec(root, print);
    std::cout << "\n";
}

void BST::postorder_rec(Node *root, void (*print)(int)) {
    if (root == nullptr) return;
    postorder_rec(root->left, print);
    postorder_rec(root->right, print);
    print(root->key);
}

void BST::postorder(void (*print)(int)) {
    std::cout << "Postorder: ";
    // TODO
    postorder_rec(root, print);
    std::cout << "\n";
}

void BST::levelOrder() {
    std::cout << "Level order: ";
    // TODO
    queue<Node *> my_queue;
    my_queue.push(root);
    while (my_queue.size() > 0) {
        Node *top = my_queue.front();
        if (top->left) my_queue.push(top->left);
        if (top->right) my_queue.push(top->right);

        cout << top->key << " ";
        my_queue.pop();
    }
}

/* This class is for practicing */

class BinaryTreeForPractice : public BST {
   public:
    Node *getRoot() { return root; }
    void setRoot(Node *root) { this->root = root; }
};

#endif  // BST_H
