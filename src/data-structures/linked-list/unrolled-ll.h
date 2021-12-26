#if !defined(UNROLLED_LINKED_LIST_H)
#define UNROLLED_LINKED_LIST_H

#include <iostream>
#include <stack>
#include <vector>

/* Node of unrolled linked list */

class UNode {
    int *arr;
    int maxSize;
    int size = 0;

   public:
    UNode *next = nullptr;
    UNode *prev = nullptr;

    UNode(int maxSize);
    ~UNode();

    int getSize() { return size; }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == maxSize; }
    bool isMin() { return size == (maxSize + 1) / 2; }
    bool isUnderFlow() { return size < (maxSize + 1) / 2; }

    void resize(int newSize);
    int getAt(int index);
    void setAt(int index, int value);
    void insertAt(int index, int value);
    void removeAt(int index);

    /* Utils */
    int front() { return getAt(0); }
    int back() { return getAt(size - 1); }
    void pushBack(int value) { insertAt(size, value); }
    void popBack() { removeAt(size - 1); }
    void pushFront(int value) { insertAt(0, value); }
    void popFront() { removeAt(0); }
};

UNode::UNode(int maxSize) : maxSize(maxSize) {
    arr = new int[maxSize];
}

UNode::~UNode() {
    delete[] arr;
    arr = nullptr;
}

void UNode::resize(int newSize) {
    if (newSize < 0 || newSize > maxSize) {
        throw "Invalid size!";
    }
    size = newSize;
}

int UNode::getAt(int index) {
    if (index < 0 || index >= size) {
        throw "Out of index!";
    }
    return arr[index];
}

void UNode::setAt(int index, int value) {
    if (index < 0 || index >= size) {
        throw "Out of index!";
    }
    arr[index] = value;
}

void UNode::insertAt(int index, int value) {
    if (isFull()) {
        throw "Node is overflow!";
    } else if (index < 0 || index > size) {
        throw "Out of index!";
    }
    size++;
    for (int i = size - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
}

void UNode::removeAt(int index) {
    if (index < 0 || index >= size) {
        throw "Out of index!";
    }
    size--;
    for (int i = index; i < size; i++) {
        arr[i] = arr[i + 1];
    }
}

/* Unrolled linked list */

class UnrolledLL {
    UNode *head = nullptr;
    UNode *tail = nullptr;
    int size = 0;
    int numOfNodes = 0;
    int nodeSize;

    UNode *allocateNode();
    void freeNode(UNode *node);

   public:
    UnrolledLL(int nodeSize) : nodeSize(nodeSize) {}
    ~UnrolledLL();
    int getNodeSize() { return nodeSize; }
    int getMinNodeSize() { return (nodeSize + 1) / 2; }

    int getSize() { return size; }
    int getNumOfNodes() { return numOfNodes; }
    bool empty() { return size == 0; }

    /* Access */
    int getAt(int index);
    void setAt(int index, int value);

    /* Basic operations */
    int firstIndexOf(int value);
    void insertAt(int index, int value);
    void removeAt(int index);
    void reverse();

    /* Utils */
    void pushBack(int value) { insertAt(size, value); }
    void popBack() { removeAt(size - 1); }
    void pushFront(int value) { insertAt(0, value); }
    void popFront() { removeAt(0); }

    /* Traverse the list */
    void traverse();

    /* Validate if the list is valid */
    void check();
};

/* Destructor */

UnrolledLL::~UnrolledLL() {
    while (head) {
        auto temp = head->next;
        delete head;
        head = temp;
    }
    tail = nullptr;
    size = numOfNodes = 0;
}

/* Memory management */

UNode *UnrolledLL::allocateNode() {
    numOfNodes++;
    return new UNode(nodeSize);
}

void UnrolledLL::freeNode(UNode *node) {
    numOfNodes--;
    delete node;
}

/* Traverse */

void UnrolledLL::traverse() {
    for (auto node = head; node; node = node->next) {
        std::cout << "|";
        for (int i = 0; i < node->getSize(); i++) {
            std::cout << node->getAt(i);
            if (i < node->getSize() - 1) {
                std::cout << " ";
            }
        }
        std::cout << "|";
        if (node->next) {
            std::cout << " - ";
        }
    }
    std::cout << "\n";
}

void UnrolledLL::check() {
    // Validate in case list is empty
    if (!head || !tail || size == 0 || numOfNodes == 0) {
        if (head && tail && size != 0 && numOfNodes != 0) {
            throw "Invalid empty list!";
        }
        return;
    }
    // Validate in case list is not empty
    if (head->prev) {
        throw "Invalid head!";
    }
    if (tail->next) {
        throw "Invalid tail!";
    }
    std::stack<UNode *> nodes;
    int totalSize = 0;
    // Traverse from head
    for (auto node = head; node; node = node->next) {
        totalSize += node->getSize();
        if (node != head) {
            if (node->getSize() < getMinNodeSize()) {
                throw "Underflow node!";
            }
        }
        nodes.emplace(node);
    }
    if (totalSize != size) {
        throw "Size mismatch!";
    }
    if (nodes.size() != numOfNodes) {
        throw "Number of nodes mismatch!";
    }
    // Traverse from tail
    for (auto node = tail; node; node = node->prev) {
        if (nodes.top() != node) {
            throw "Broken link!";
        }
        nodes.pop();
    }
    if (!nodes.empty()) {
        throw "Broken link!";
    }
}

/* Test utils */

typedef UnrolledLL Ull;

class Op {
   protected:
    Ull *pll;
    std::vector<int> args;

   public:
    Op(Ull *pll, std::vector<int> args) : pll(pll), args(args) {}
    virtual void run() = 0;
    void runAndCheck() {
        run();
        pll->check();
        pll->traverse();
        std::cout << "\n";
    }
};

class InsertAt : public Op {
   public:
    InsertAt(Ull *pll, std::vector<int> args) : Op(pll, args) {}
    void run() {
        std::cout << "Insert value " << args[1] << " at index " << args[0] << "\n";
        pll->insertAt(args[0], args[1]);
    }
};

class RemoveAt : public Op {

   public:
    RemoveAt(Ull *pll, std::vector<int> args) : Op(pll, args) {}
    void run() {
        std::cout << "Remove at index " << args[0] << "\n";
        pll->removeAt(args[0]);
    }
};
class RemoveFirst : public Op {
   public:
    RemoveFirst(Ull *pll, std::vector<int> args) : Op(pll, args) {}
    void run() {
        std::cout << "Remove first occurence of value " << args[0] << "\n";
        int index = pll->firstIndexOf(args[0]);
        if (index != -1) {
            pll->removeAt(index);
        }
    }
};

class PushBack : public Op {
   public:
    PushBack(Ull *pll, std::vector<int> args) : Op(pll, args) {}
    void run() {
        std::cout << "Push back value " << args[0] << "\n";
        pll->pushBack(args[0]);
    }
};

class PushFront : public Op {
   public:
    PushFront(Ull *pll, std::vector<int> args) : Op(pll, args) {}
    void run() {
        std::cout << "Push front value " << args[0] << "\n";
        pll->pushFront(args[0]);
    }
};

class PopBack : public Op {
   public:
    PopBack(Ull *pll, std::vector<int> args) : Op(pll, args) {}
    void run() {
        std::cout << "Pop back\n";
        pll->popBack();
    }
};

class PopFront : public Op {
   public:
    PopFront(Ull *pll, std::vector<int> args) : Op(pll, args) {}
    void run() {
        std::cout << "Pop front\n";
        pll->popFront();
    }
};

class Reverse : public Op {
   public:
    Reverse(Ull *pll, std::vector<int> args) : Op(pll, args) {}
    void run() {
        std::cout << "Reverse\n";
        pll->reverse();
    }
};

#endif  // UNROLLED_LINKED_LIST_H