//DONE
#include "queue.h"

using namespace std;

int main() {
    QueueCircularLL myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);

    while (!myQueue.empty()) {
        myQueue.front() *= 2;
        cout << myQueue.front() << " ";
        myQueue.rear()--;
        myQueue.dequeue();
    }

    return 0;
}

/* Constructor and destructor */
QueueCircularLL::QueueCircularLL() {
    // TODO
    rearNode = NULL;
}

QueueCircularLL::~QueueCircularLL() {
    // TODO
    clear();
}

/* Basic operations */

bool QueueCircularLL::empty() {
    // TODO
    if(rearNode == nullptr) return true;
    return false;
}

void QueueCircularLL::enqueue(int value) {
    // TODO
    if(rearNode == NULL){
        rearNode = new QueueNode(value);
        return;
    }
    QueueNode *pCr = rearNode;
    while(pCr->next!=NULL){
        pCr=pCr->next;
    }
    pCr->next = new QueueNode(value);
}

void QueueCircularLL::dequeue() {
    if (empty()) return;
    // TODO
    QueueNode *pRoot = rearNode;
    rearNode = rearNode->next;
    delete pRoot;
    pRoot = NULL;
}

int &QueueCircularLL::front() {
    if (empty()) {
        throw "Queue is empty!";
    }
    // TODO
    return rearNode->value;
}

int &QueueCircularLL::rear() {
    if (empty()) {
        throw "Queue is empty!";
    }
    // TODO
    QueueNode *pCr = rearNode;
    while(pCr->next!=NULL){
        pCr=pCr->next;
    }
    return pCr->value;
}

void QueueCircularLL::clear() {
    // TODO //loop to remove, delete, assign NULL
    while(rearNode!=NULL){
        QueueNode *pCr = rearNode;
        rearNode = rearNode->next;
        delete pCr;
        pCr = NULL;
    }
}
