#include "my-lib.h"
#include "sort.h"

using namespace std;

int getParent(int index){
    return (index-1)/2;
}

int getLeft(int index){
    return index*2+1;
}

int getRight(int index){
    return index*2+2;
}

template <class T>
void heapDown(vector<T> &data,int index,int size){
    int left = getLeft(index),right = getRight(index);
    int largest = index;
    if(left < size && data[left] > data[largest]){
        largest = left;
    }
    if(right < size && data[right] > data[largest]){
        largest = right;
    }
    if(largest != index){
        swap(data[largest],data[index]);
        heapDown(data,largest,size);
    }
}


template <class T>
void buildHeap(vector<T> &data){
    int size = data.size();
    int notLeaf = (data.size())/2-1;

    for(int i = notLeaf;i >= 0;i--){
        heapDown(data,i,size-1);
    }
}

template <class T>
void heapSort(vector<T> &data) {
    // TODO
    buildHeap(data);
    // Largest element go to right.
    for(int size = data.size()-1; size >0 ; size--){
        swap(data[0],data[size]);
        //heap down with size-- cause max in right.
        heapDown(data,0,size);
    }
}

int main() {
    srand(time(0));
    vector<int> data;

    data = generateVector(10);
    printContainer(data);

    heapSort(data);
    printContainer(data);
    cout << "\n";

    auto stableData = getUnsortedStableData();
    heapSort(stableData);
    printSortData(stableData);

    return 0;
}
