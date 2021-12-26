//DONE
#include "stack.h"

using namespace std;

int main() {
    StackLL st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    while (!st.empty()) {
        st.top() *= 2;
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

/* Destructor */

StackLL::~StackLL() {
    // TODO
    clear();
}

/* Basic operations */

bool StackLL::empty() {
    // TODO
    if(head == NULL) return true;
    return false;
}

void StackLL::push(int value) {
    // TODO
    if(head == NULL){
        head = new StackNode(value);
        return;
    }
    StackNode *pCr = head;
    while(pCr->next){
        pCr = pCr->next;
    }
    pCr->next = new StackNode(value);
}

void StackLL::pop() {
    if(empty()) return;
    // TODO
    StackNode *pCr = head;
    StackNode *walker = nullptr;
    while(pCr->next){
        walker = pCr;
        pCr = pCr->next;
    }
    if(!walker){
        delete head;
        head = nullptr;
        return;
    }
    walker->next = nullptr;
}

int &StackLL::top() {
    if (empty()) {
        throw "Stack is empty!";
    }
    // TODO
    StackNode *pCr = head;
    while(pCr->next){
        pCr = pCr->next;
    }
    return pCr->value;
}

void StackLL::clear() {
    // TODO
    while(head){
        StackNode *pDel = head;
        head = head->next;
        delete pDel;
        pDel = nullptr;
    }
}
