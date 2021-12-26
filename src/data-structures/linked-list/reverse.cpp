#include "sll.h"

using namespace std;

SNode *reverseRecursive(SNode *head) {
    //3-2-1   
    // 1 return head, start from 2, 1->next =2, 2->next = null
    if(head->next == nullptr)
        return head;
    
    SNode* p_next = reverseRecursive(head->next);
    head->next->next=head;
    head->next = nullptr;
    return p_next; 
}

SNode *reverseIterative(SNode *head) {
    //1,2,3
    SNode* pPrev = nullptr;
    SNode* pNext;
    while(head){
        pNext= head->next;
        head->next = pPrev;
        pPrev = head;
        head = pNext;
    }

    return pPrev; 
}

int main() {
    SLLForPractice sll;
    for (auto &&ele : {1,2,3,4,5,6}) {
        sll.pushFront(ele);
    }

    sll.traverse();

    // Reverse using recursion
    sll.setHead(reverseRecursive(sll.getHead()));
    sll.traverse();

    // Reverse using iteration
    sll.setHead(reverseIterative(sll.getHead()));
    sll.traverse();

    return 0;
}
