#include <iostream>

using namespace std;

struct AVL {
    int val;
    AVL *left = nullptr;
    AVL *right = nullptr;
    int height = 0;
    AVL(int val) : val(val){};
};

int getHeight(AVL *head) {
    if (head == nullptr) return 0;
    return head->height;
}

int getBalance(AVL *head) {
    if (head == nullptr) return 0;
    return getHeight(head->left) - getHeight(head->right);
}

void preOrder(AVL *head) {
    if (head == nullptr) return;
    cout << head->val << " ";
    preOrder(head->left);
    preOrder(head->right);
}

AVL *rotateLeft(AVL *head) {
    AVL *right = head->right;
    AVL *leftOfRight = right->left;
    //swap
    right->left = head;
    head->right = leftOfRight;
    //update height
    head->height = 1 + max<int>(getHeight(head->left), getHeight(head->right));
    right->height = 1 + max<int>(getHeight(right->left), getHeight(right->right));
    return right;
}

AVL *rotateRight(AVL *head) {
    AVL *left = head->left;
    AVL *rightOfLeft = left->right;
    //swap
    left->right = head;
    head->left = rightOfLeft;
    //update height
    head->height = 1 + max<int>(getHeight(head->left), getHeight(head->right));
    left->height = 1 + max<int>(getHeight(left->left), getHeight(left->right));
    return left;
}

AVL *insert(AVL *head, int val) {
    if (head == nullptr) {
        return new AVL(val);
    }
    if (val < head->val) {
        head->left = insert(head->left, val);
    } else {
        head->right = insert(head->right, val);
    }
    //update height
    head->height = 1 + max<int>(getHeight(head->left), getHeight(head->right));

    int balance = getBalance(head);
    //LL
    if (balance > 1 && getBalance(head->left) >= 0) {
        return rotateRight(head);
    }
    //LR
    if (balance > 1 && getBalance(head->left) < 0) {
        head->left = rotateLeft(head->left);
        return rotateRight(head);
    }
    //RR
    if (balance < -1 && getBalance(head->right) <= 0) {
        return rotateLeft(head);
    }
    //RL
    if (balance < -1 && getBalance(head->right) > 0) {
        head->right = rotateRight(head->right);
        return rotateLeft(head);
    }
    return head;
}

AVL *deleteNode(AVL *head, int val) {
    if (!head) return nullptr;
    if (val < head->val) {
        head->left = deleteNode(head->left, val);
    } else if (val > head->val) {
        head->right = deleteNode(head->right, val);
    } else {
        if (!head->left) {
            return head->right;
        } else if (!head->right) {
            return head->left;
        } else {
            AVL *right = head->right;
            while (right->left) {
                right = right->left;
            }
            head->val = right->val;
            head->right = deleteNode(head->right, right->val);
        }
    }
    //step 2
    if (head == nullptr) {
        return head;
    }
    //update height
    head->height = 1 + max<int>(getHeight(head->left), getHeight(head->right));

    //getBalance
    int balance = getBalance(head);
    // 4 TH
    //LL
    if (balance > 1 && getBalance(head->left) >= 0) {
        return rotateRight(head);
    }
    //LR
    if (balance > 1 && getBalance(head->left) < 0) {
        head->left = rotateLeft(head->left);
        return rotateRight(head);
    }
    //RR
    if (balance < -1 && getBalance(head->right) <= 0) {
        return rotateLeft(head);
    }
    //RL
    if (balance < -1 && getBalance(head->right) > 0) {
        head->right = rotateRight(head->right);
        return rotateLeft(head);
    }
    return head;
}
