#if !defined(STACK_H)
#define STACK_H

#include <iostream>
#include <vector>

/* Abstract stack */
class Stack {
   public:
    virtual bool empty() = 0;
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual int &top() = 0;
    virtual void clear() = 0;
};

/* Array implementation of stack */
class StackArray : public Stack {
    int *arr;
    int capacity;
    int size = 0;

   public:
    StackArray(int capacity);
    ~StackArray();

    bool full();
    bool empty();
    void push(int value);
    void pop();
    int &top();
    void clear();
};

/* Singly linked list implementation of stack */
struct StackNode {
    int value;
    StackNode *next;
    StackNode(int value, StackNode *next = nullptr) : value(value), next(next) {}
};

class StackLL : public Stack {
    StackNode *head;

   public:
    StackLL() {head = nullptr;};
    ~StackLL();

    bool empty();
    void push(int value);
    void pop();
    int &top();
    void clear();
};

#endif  // STACK_H
