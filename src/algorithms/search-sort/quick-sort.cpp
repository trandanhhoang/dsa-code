#include "my-lib.h"
#include "sort.h"

using namespace std;

//function to choose PIVOT
// dau - cuoi - giua - random

// patition scheme ez : lomulto -> no performance
// patition scheme: LL pointer
// patition scheme: LR pointer

//tail core: cach de? de. quy ko luu stack cua? ham` => best performance.

//max: time complexity O(n^2), space : bth laf O(n), co cach de? con o(logn) -> TAIL CALL

//MEDIAN OF THREE

// template <class T>
// int Lomuto(vector<T> &data,int left,int right) {
//     // TODO
//     //pick pivot and swap to right
//     int pivot = left + rand() % (right - left + 1);
//     swap(data[pivot],data[right]);
//     //sort
//     int min_index = left;
//     for(int i = left;i < right;i++){
//         if(data[i]<data[right]){
//             swap(data[i],data[min_index]);
//             min_index++;
//         }
//     }
//     //swap pivot and return
//     swap(data[min_index],data[right]);
//     return min_index;
// }

// template <class T>
// int Hoare(vector<T> &data, int left, int right) {
//     // TODO
//     // no need swap
//     auto pivot = data[left];  // can't pick RIGHT
//     // swap(data[pivot],data[right]);
//     int left_2nd = left, right_2nd = right;
//     while (1) {
//         while (data[left_2nd] < pivot) {
//             left_2nd++;
//         }
//         while (data[right_2nd] > pivot) {
//             right_2nd--;
//         }
//         if (left_2nd >= right_2nd) break;
//         swap(data[left_2nd++], data[right_2nd--]);
//     }
//     return right_2nd;
// }

// //
// template <class T>
// void quickSort_h(vector<T> &data, int left, int right) {
//     // TODO
//     //condition to stop
//     if (left >= right) return;
//     //call quick sort, 2 approach: LOMUTO or HOARE
//     int middle = Hoare(data, left, right);
//     //sort left
//     quickSort_h(data, left, middle);
//     //sort right
//     quickSort_h(data, middle + 1, right);
// }


// template <class T>
// void quickSort(vector<T> &data) {
//     // TODO
//     quickSort_h(data, 0, data.size() - 1);
// }

/* Test */

template <class T>
int quickSortOfHelper(vector<T> &data,int left,int right) {
    int pivot = left;
    int leftWalker = left+1;
    int rightWalker = right;
    while(leftWalker <= rightWalker){
        while(leftWalker <= rightWalker && data[leftWalker] < data[pivot]){
            leftWalker++;
        }
        while (data[rightWalker] >= data[pivot] && leftWalker <= rightWalker){
            rightWalker--;
        }
        if(leftWalker>=rightWalker){
            break;
        }
        swap(data[leftWalker],data[rightWalker]);
    }
    swap(data[pivot],data[rightWalker]);
    return rightWalker;
}

template <class T>
void helper(vector<T> &data,int left,int right) {
    if(left == right || left > right || right<left){
        return;
    }
    int middle = quickSortOfHelper(data,left,right);
    helper(data,left,middle-1);
    helper(data,middle+1,right);
}

template <class T>
void quickSort(vector<T> &data) {
    int left = 0;
    int right = data.size()-1;
    helper(data,left,right);
}

int main() {
    srand(time(0));
    vector<int> data;

    data = generateVector(25);
    printContainer(data);
    quickSort(data);
    printContainer(data);
    cout << "\n";

    auto stableData = getUnsortedStableData();
    quickSort(stableData);
    printSortData(stableData);
    return 0;
}
