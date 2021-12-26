#include <unordered_set>

#include "sll.h"

using namespace std;

bool detectLoop(SNode *head) {
    SNode *slow = head;
    SNode *fast = head;
    while (fast->next && fast) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
}

void removeLoop(SNode *head) {
}

/* Testing */

SNode *createLoop(SNode *head, int value);
void traverseLoop(SNode *head);

int main() {
    SLLForPractice sll;
    for (auto &&ele : {6, 5, 4, 3, 2, 1}) {
        sll.pushFront(ele);
    }

    // Create loop
    int pointedValue = 4;
    cout << "Point tail o node " << pointedValue << "\n";
    auto tail = createLoop(sll.getHead(), pointedValue);
    traverseLoop(sll.getHead());

    // Find and remove loop
    if (detectLoop(sll.getHead())) {
        removeLoop(sll.getHead());
        cout << "Loop detected and removed\n";
        traverseLoop(sll.getHead());
    } else {
        cout << "Loop not found\n";
    }

    // Force remove loop in case manually remove failed
    tail->next = nullptr;

    return 0;
}

SNode *createLoop(SNode *head, int value) {
    auto node = head, pointed = head, tail = head;
    while (node) {
        if (node->key == value)
            pointed = node;
        if (!node->next)
            tail = node;
        node = node->next;
    }
    tail->next = pointed;
    return tail;
}

void traverseLoop(SNode *head) {
    unordered_set<SNode *> nodes;
    cout << "Traverse: ";
    while (head && nodes.find(head) == nodes.end()) {
        cout << head->key << "->";
        nodes.insert(head);
        head = head->next;
    }
    if (head) {
        cout << head->key;
    } else {
        cout << "NULL";
    }
    cout << "\n";
}

//DONE
// SNode *p_slow = head,*p_fast = head;
// while(p_fast && p_fast->next){
// p_fast=p_fast->next->next;
// p_slow=p_slow->next;
// if(p_fast == p_slow){ // slow move 1, check go in loop, n^2
// p_slow = head;
// SNode *p_check;
// while (1) {
// p_check = p_fast;
// // 2 condition
// while (p_check->next != p_fast && p_check->next != p_slow){
// p_check = p_check->next;
// }

// if (p_check->next == p_slow)
// break;

// p_slow = p_slow->next;
// }

// p_check->next = NULL;
// }
// }
