//DONE
#include "queue.h"

using namespace std;

int main() {
    QueueCircularBuffer myQueue(5);

    int i = 1;
    while (!myQueue.full()) {
        myQueue.enqueue(i++);
    }

    while (!myQueue.empty()) {
        myQueue.front() *= 2;
        cout << myQueue.front() << " ";
        myQueue.rear()--;
        myQueue.dequeue();
    }

    return 0;
}

/* Constructor and destructor */

QueueCircularBuffer::QueueCircularBuffer(int capacity) : capacity(capacity),
                                                         arr(new int[capacity]) {
    // TODO
    iFront = 0; iRear = -1;
}

QueueCircularBuffer::~QueueCircularBuffer() {
    // TODO
    delete[] arr;
    arr = nullptr;
}

/* Basic operations */

bool QueueCircularBuffer::full() {
    // TODO
    if(iRear + iFront == capacity - 1){
        return true;
    }
    return false;
}

bool QueueCircularBuffer::empty() {
    // TODO
    if(iFront - iRear == 1) return true;
    return false;
}

void QueueCircularBuffer::enqueue(int value) {
    if (full()) {
        throw "Queue is full!";
    }
    // TODO
    iRear += 1;
    arr[iRear % capacity] = value;
}

void QueueCircularBuffer::dequeue() {
    // TODO
    if (empty()) return;
    iFront += 1;
}

int &QueueCircularBuffer::front() {
    if (empty()) {
        throw "Queue is empty!";
    }
    // TODO
    return arr[iFront % capacity];
}

int &QueueCircularBuffer::rear() {
    if (empty()) {
        throw "Queue is empty!";
    }
    // TODO
    return arr[iRear % capacity];
}

void QueueCircularBuffer::clear() {
    // TODO
    iFront = 0; iRear = -1;
}
