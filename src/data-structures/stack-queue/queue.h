#if !defined(QUEUE_H)
#define QUEUE_H

#include <iostream>
#include <vector>

/* Abstract queue */
class Queue {
   public:
    virtual bool empty() = 0;
    virtual void enqueue(int value) = 0;
    virtual void dequeue() = 0;
    virtual int &front() = 0;
    virtual int &rear() = 0;
    virtual void clear() = 0;
};

struct QueueNode {
    int value;
    QueueNode *next;
    QueueNode(int value, QueueNode *next = nullptr) : value(value), next(next) {}
};

/* Array implementation of circular queue */
class QueueCircularBuffer : public Queue {
    int *arr;
    int capacity;
    int iFront, iRear;

   public:
    QueueCircularBuffer(int capacity);
    ~QueueCircularBuffer();

    bool full();
    bool empty();
    void enqueue(int value);
    void dequeue();
    int &front();
    int &rear();
    void clear();
};

/* Linked list implementation of circular queue */
class QueueCircularLL : public Queue {
    QueueNode *rearNode;  // Rear points to front

   public:
    QueueCircularLL();
    ~QueueCircularLL();

    bool empty();
    void enqueue(int value);
    void dequeue();
    int &front();
    int &rear();
    void clear();
};

#endif  // QUEUE_H
