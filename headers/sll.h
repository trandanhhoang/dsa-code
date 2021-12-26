#if !defined(SINGLY_LINKED_LIST_H)
#define SINGLY_LINKED_LIST_H

#include <iostream>
using namespace std;

struct SNode {
    int key;
    SNode *next = nullptr;
    SNode(int key) : key(key) {}
    SNode(int key, SNode *next) : key(key), next(next) {}
};

class SLL {
   protected:
    SNode *head = nullptr;
    int size = 0;
    // void SLL::insertp2pREAL(SNode **head,int index,int value);

   public:
    ~SLL();

    int getSize() { return size; }
    bool empty() { return size == 0; }

    /* Basic operations */

    bool search(int value);
    void insertAt(int index, int value);
    void pushFront(int value);
    void remove(int value);
    void removeAt(int index);
    void popFront();
    void clear();
    void traverse(std::string separator = "->");

    void insertAtP2p(int index,int value);
    // SNode *&SLL::find(SNode **head,int index,int value);

    /* Iterator */

    class Iterator {
        SNode *node = nullptr;

       public:
        Iterator() = default;
        Iterator(SNode *head) : node(head) {}
        int &operator*();
        Iterator operator++(int);
        bool operator!=(const Iterator &that);
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(); }
};

/* Destructor */

SLL::~SLL() {
    // TODO
    this->clear();
}

/* Basic operations */

// SNode *&SLL::find(SNode **head,int index,int value){
//     SNode *p;
//     while(index>0){
//         p = *head
//     }
//     return 
// }

// void SLL::insertp2pREAL(SNode **head,int index,int value){
//     SNode *new_node = find(head,index,value);
// }

void SLL::insertAtP2p(int index, int value) {
    if (index < 0 || index > size) {
        throw "Out of index!";
    }
    size++;
    //  TODO
    SNode **ptrHead = &head;
    SNode *pCr = new SNode(value);

    while(index>0){
        ptrHead = &((*ptrHead)->next);
        index--;
    }
    pCr->next = (*ptrHead); 
    (*ptrHead) = pCr;

    // SNode **ptr_Head = &head;
    // SNode *pCr= new SNode(value);
    // while(index>1){
    //     *ptr_Head
    // }
}

bool SLL::search(int value) {
    // TODO
    SNode *p = head;
    while(p!= NULL){
        if(p->key==value) return 1;
        p=p->next;
    }
    return false;
}

void SLL::insertAt(int index, int value) {
    if (index < 0 || index > size) {
        throw "Out of index!";
    }
    size++;
    // TODO
    SNode *p = new SNode(value);
    if(index ==0){
        p->next=head;
        head=p;
        return;
    }
    SNode *pCr = head;
    while(index>1){
        pCr=pCr->next;
        index--;
    }
    p->next=pCr->next;
    pCr->next=p;
    
}

void SLL::pushFront(int value) {
    // TODO
    size++;
    SNode *p = new SNode(value);
    p->next = NULL; 
    if(this->head == NULL){
        this->head = p;
        return;
    }

    p->next = this->head;
    this->head = p;    
}

void SLL::remove(int value) {
    // TODO
    size--;
    SNode *p = head;
    int index=0;
    while(p->next!=NULL){
        if(index == 0 && p->key==value){//del at head
            SNode *p=head;
            head=head->next;
            delete p;
        }
        if(p->next->key==value){
            p->next= p->next->next;
        }
        p=p->next;
        index++;
    }
}

void SLL::removeAt(int index) {
    if (index < 0 || index >= size) {
        throw "Out of index!";
    }
    // TODO
    size--;
    if(index == 0){
        SNode *p = head;
        head = head->next;
        delete p;
        return;
    }
    SNode *pCr= head;
    while(index>1){
        pCr=pCr->next;
        index--;
    }
    SNode *pNext = pCr->next;
    pCr->next=pNext->next;
    //0 1 2 3    
}

void SLL::popFront() {
    if(size==0){
        return;
    }
    size--;
    SNode *p = head;
    head = head->next;
    delete p ;
}

void SLL::clear() {
    // TODO
    while(head!=NULL){
        SNode *p=head;
        head=head->next;
        delete p;
    }
    size=0;
}

/* Traversal */

void SLL::traverse(std::string separator) {
    std::cout << "Traverse: ";
    // TODO
    SNode *p=head;
    while(p!=NULL){
        cout<< p->key<<" ";
        p=p->next;
    }
    
    std::cout << "\n";
}

/* Iterator */

int &SLL::Iterator::operator*() {
    return node->key;
}

SLL::Iterator SLL::Iterator::operator++(int) {
    auto before = SLL::Iterator(node);
    node = node->next;
    return before;
}

bool SLL::Iterator::operator!=(const Iterator &that) {
    return node != that.node;
}

/* This class is for practicing  */

class SLLForPractice : public SLL {
   public:
    SNode *getHead() { return head; }
    void setHead(SNode *head) { this->head = head; }
};

#endif  // SINGLY_LINKED_LIST_H
