#include "unrolled-ll.h"

#include <vector>
using namespace std;

/* Test utils */

int main() {
    UnrolledLL ll(5);

    vector<Op *> ops = {
        // Insert
        new PushBack(&ll, {60}),
        new PushBack(&ll, {70}),
        new PushFront(&ll, {50}),
        new PushFront(&ll, {20}),
        new PushFront(&ll, {10}),
        new InsertAt(&ll, {2, 40}),
        new InsertAt(&ll, {2, 30}),
        new PushBack(&ll, {90}),
        new PushBack(&ll, {100}),
        new InsertAt(&ll, {7, 80}),
        new PushBack(&ll, {110}),
        new PushBack(&ll, {120}),
        // Reverse
        new Reverse(&ll, {}),
        // Delete
        new PopFront(&ll, {}),
        new RemoveAt(&ll, {5}),
        new RemoveFirst(&ll, {80}),
        new PopFront(&ll, {}),
        new PopFront(&ll, {}),
        new PopFront(&ll, {}),
        new RemoveAt(&ll, {2}),
        new RemoveAt(&ll, {0}),
        new RemoveAt(&ll, {3}),
        new PopBack(&ll, {}),
        new PopBack(&ll, {}),
        new RemoveFirst(&ll, {50}),
    };

    try {
        for (auto &&op : ops) {
            op->runAndCheck();
            delete op;
            op = nullptr;
        }

        // Test access
        cout << "Test access\n";
        srand(time(0));
        for (int i = 0; i < 15; i++) {
            ll.pushBack(rand() % 89 + 10);
        }
        ll.traverse();
        cout << "Increase all element by one\n";
        for (int i = 0; i < 15; i++) {
            ll.setAt(i, ll.getAt(i) + 1);
        }
        ll.traverse();
        cout << "\n";

        cout << "All testcases passed!\n";

    } catch (const char *e) {
        cout << e << "\n";
    }

    return 0;
}

/* Access */

int UnrolledLL::getAt(int index) {
    if (index < 0 || index >= size) {
        throw "Out of index!";
    }
    // TODO
}

void UnrolledLL::setAt(int index, int value) {
    if (index < 0 || index >= size) {
        throw "Out of index!";
    }
    // TODO
}

/* Find the index of first occurrence of value */
int UnrolledLL::firstIndexOf(int value) {
    // TODO
    return -1;
}

/*
 * Don't call new or delete directly:
 * - Create node: Use allocateNode()
 * - Delete node: Use freeNode()
 */

/* Split if node is full */
void UnrolledLL::insertAt(int index, int value) {
    if (index < 0 || index > size) {
        throw "Out of index!";
    }
    // TODO
    UNode *p_Cur = head;
    while(index>0){
        p_Cur=p_Cur->next;
    }
    //2TH
    if(!p_Cur->isFull()){// TH1: 
        p_Cur->setAt( p_Cur->getSize() , value);
    }
    else{
        UNode *newNode = new UNode(p_Cur->getSize());
        while(!newNode->
    }
    
}

/* Steal element or merge if node is min */
void UnrolledLL::removeAt(int index) {
    if (index < 0 || index >= size) {
        throw "Out of index!";
    }
    // TODO
}

/* Reverse the linked list */
void UnrolledLL::reverse() {
    // TODO
}