#if !defined(SINGLY_LINKED_LIST_H)
#define SINGLY_LINKED_LIST_H

#include <iostream>

struct SNode {
    int key;
    SNode *next = nullptr;
    SNode(int key) : key(key) {}
    SNode(int key, SNode *next) : key(key), next(next) {}
};

class SLL {
   protected:
    SNode *head = nullptr;
    int size = 0;

   public:
    ~SLL();

    int getSize() { return size; }
    bool empty() { return size == 0; }

    /* Basic operations */

    bool search(int value);
    void insertAt(int index, int value);
    void pushFront(int value);
    void remove(int value);
    void removeAt(int index);
    void popFront();
    void clear();
    void traverse(std::string separator = "->");

    /* Iterator */

    class Iterator {
        SNode *node = nullptr;

       public:
        Iterator() = default;
        Iterator(SNode *head) : node(head) {}
        int &operator*();
        Iterator operator++(int);
        bool operator!=(const Iterator &that);
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(); }
};

/* Destructor */

SLL::~SLL() {
    // TODO
}

/* Basic operations */

bool SLL::search(int value) {
    // TODO
}

void SLL::insertAt(int index, int value) {
    if (index < 0 || index > size) {
        throw "Out of index!";
    }
    // TODO
}

void SLL::pushFront(int value) {
    // TODO
}

void SLL::remove(int value) {
    // TODO
}

void SLL::removeAt(int index) {
    if (index < 0 || index >= size) {
        throw "Out of index!";
    }
    // TODO
}

void SLL::popFront() {
    // TODO
}

void SLL::clear() {
    // TODO
}

/* Traversal */

void SLL::traverse(std::string separator) {
    std::cout << "Traverse: ";
    // TODO
    std::cout << "\n";
}

/* Iterator */

int &SLL::Iterator::operator*() {
    return node->key;
}

SLL::Iterator SLL::Iterator::operator++(int) {
    auto before = SLL::Iterator(node);
    node = node->next;
    return before;
}

bool SLL::Iterator::operator!=(const Iterator &that) {
    return node != that.node;
}

/* This class is for practicing  */

class SLLForPractice : public SLL {
   public:
    SNode *getHead() { return this->head; }
    void setHead(SNode *head) {
        this->head = head;
        this->size = 0;
        while (head) {
            this->size++;
            head = head->next;
        }
    }
};

#endif  // SINGLY_LINKED_LIST_H
