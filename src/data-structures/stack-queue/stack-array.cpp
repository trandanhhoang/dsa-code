//DONE
#include "stack.h"

using namespace std;

int main() {
    StackArray st(5);

    int i = 1;
    while (!st.full()) {
        st.push(i++);
    }

    while (!st.empty()) {
        st.top() *= 2;
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

/* Constructor and destructor */

StackArray::StackArray(int capacity) : capacity(capacity),
                                       arr(new int[capacity]) {}

StackArray::~StackArray() {
    // TODO
    delete[] arr;
    arr = nullptr;
}

/* Basic operations */

bool StackArray::full() {
    // TODO
    if(size == capacity) return true;
    return false;
}

bool StackArray::empty() {
    // TODO
    if(size==0) return true;
    return false;
}

void StackArray::push(int value) {
    if (full()) {
        throw "Stack is full!";
    }
    // TODO
    arr[size++] = value;
}

void StackArray::pop() {
    if (empty()) return;
    // TODO
    size--;
}

int &StackArray::top() {
    if (empty()) {
        throw "Stack is empty!";
    }
    // TODO
    return arr[size-1];
}

void StackArray::clear() {
    // TODO
    size = 0;
}
