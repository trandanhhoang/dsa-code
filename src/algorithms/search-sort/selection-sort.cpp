#include "my-lib.h"
#include "sort.h"

using namespace std;
//ko on dinh, NOT STALBE
//all case:best case: n^2
// template <class T>
// void selectionSort(vector<T> &data) {
//     int size = data.size();
//     T min;
//     int min_index;
//     for(int i = 0;i < size-1;i++){
//         min_index = i;
//         //search min of REST -> READ
//         for(int j = i+1;j<size;j++){
//             if(data[j] < data[min_index]){
//                 min_index = j;
//             }
//         }
//         //swap 1 time for 1 index -> N WRITE, STORE
//         swap(data[i],data[min_index]);
//     }
// }
template <class T>
void selectionSort(vector<T> &data) {
    int size = data.size();

    for(int j = 0;j<size-1;j++){
        T min = data[j];
        int indexMin = j;
        for(int i = j;i<size;i++){
            if(data[i]<min){
                indexMin = i;
                min = data[i];
            }
        }
        swap(data[j],data[indexMin]);
    }
}

int main() {
    srand(time(0));
    vector<int> data;

    data = generateVector(25);
    selectionSort(data);
    printContainer(data);
    cout << "\n";

    auto stableData = getUnsortedStableData();
    selectionSort(stableData);
    printSortData(stableData);

    return 0;
}
