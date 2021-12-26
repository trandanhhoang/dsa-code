#if !defined(HEAP_H)
#define HEAP_H

#include <iostream>
#include <vector>

using namespace std;

/* Helper */

int getParent(int child) {
    // TODO
    return (child - 1) / 2;
}

int getLeft(int parent) {
    // TODO
    return parent * 2 + 1;
}

int getRight(int parent) {
    // TODO
    return parent * 2 + 2;
}

/* Build heap in O(nlogn) */

void upHeap(vector<int> &heap, int i) {
    // TODO
    if (i == 0) return;
    int parent = getParent(i);
    //check child > paren => swap
    if (heap[i] > heap[parent]) {
        int swap = heap[i];
        heap[i] = heap[parent];
        heap[parent] = swap;
        upHeap(heap, parent);
    }
}

// time: O(nlogn)
vector<int> buildHeapUnoptimized(vector<int> &init) {
    // TODO
    vector<int> new_heap;
    //insert into new heap and heap up
    for (int i = 0; i < init.size(); i++) {
        new_heap.emplace_back(init[i]);
        upHeap(new_heap, i);
    }
    return new_heap;
}

/* Build heap in O(n) - Bottom-up construction */
void downHeap(vector<int> &heap, int i) {
    int l_child = getLeft(i);
    int r_child = getRight(i);
    int size = heap.size();
    int largest = i;
    //step 1: check left -> new largest
    if (l_child < size && heap[l_child] > heap[largest]) {
        largest = l_child;
    }
    //step 2: check right -> new largest
    if (r_child < size && heap[r_child] > heap[largest]) {
        largest = r_child;
    }
    // Swap and Heap down
    if (largest != i) {
        int swap = heap[i];
        heap[i] = heap[largest];
        heap[largest] = swap;
        downHeap(heap, largest);
    }
}

void buildHeap(vector<int> &heap) {
    // TODO
    int size = heap.size();
    //heap down from node is NOT LEAF. coil(size / 2)
    for (int i = size / 2; i >= 0; i--) {
        downHeap(heap, i);
    }
}

/* IO utils */

void print(vector<int> &heap) {
    std::cout << "Heap: ";
    for (auto &&ele : heap) {
        cout << ele << " ";
    }
    cout << "\n";
}

#endif  // HEAP_H
