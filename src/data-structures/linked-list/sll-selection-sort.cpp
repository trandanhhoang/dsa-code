#include "my-lib.h"
#include "sll.h"

using namespace std;

SNode *find_min(SNode*& head){
    SNode **p_root = &head;
    SNode **p_min = p_root;
    
    int min = INT16_MAX;

    while((*p_root)){
        if(min > (*p_root)->key){
            min = (*p_root)->key;
            p_min = p_root;
        }
        p_root = &((*p_root)->next);      
    }

    SNode *p_ret = *p_min;
    *p_min = (*p_min)->next;
    p_ret->next = nullptr;
    return p_ret;
}

/* Remember: Manipulating pointer, not swap data */
SNode *selectionSort(SNode *head) {
    // TODO
    SNode* new_node = find_min(head);
    SNode* ret_node = new_node;
    while(head){
        new_node->next = find_min(head);
        new_node = new_node->next;
    }
    return ret_node;
}

int main() {
    srand(time(0));
    SLLForPractice sll;

    for (auto &&ele : generateVector(20)) {
        sll.pushFront(ele);
    }

    sll.traverse();
    sll.setHead(selectionSort(sll.getHead()));
    sll.traverse();

    return 0;
}