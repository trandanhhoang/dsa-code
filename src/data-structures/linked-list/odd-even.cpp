#include "sll.h"

using namespace std;

/*
 * Group the list by odd-even index, odd index followed by even index
 * Note: We talk about index, not value
 */

// O(n) time, O(1) space
SNode *oddEven(SNode *head) {
    // TODO
    SNode *pCr1 = head;
    SNode *pCr2 = head->next, *pStart2 = pCr2;
    //1-2-3-4-5
    //transform => 1-3-5-2-4
    while (pCr1->next && pCr1->next->next) {
        pCr1->next = pCr2->next;
        pCr1 = pCr1->next;
        pCr2->next = pCr1->next;
        pCr2 = pCr2->next;
    }
    pCr1->next = pStart2;

    return head;
}

int main() {
    SLLForPractice sll;

    // Even numbers of node
    for (auto &&ele : {1, 3, 8, 9, 10, 6, 1, 8}) {
        sll.pushFront(ele);
    }
    sll.traverse();
    cout << endl;
    sll.setHead(oddEven(sll.getHead()));
    sll.traverse();  // 6 9 3 10 8 1
    cout << endl;

    // Odd numbers of node
    sll.clear();
    for (auto &&ele : {10, 5, 2, 4, 7}) {
        sll.pushFront(ele);
    }
    sll.traverse();
    cout << endl;
    sll.setHead(oddEven(sll.getHead()));
    sll.traverse();  // 7 2 10 4 5
    cout << endl;
    return 0;
}
