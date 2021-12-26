#include "my-lib.h"
#include "sort.h"

using namespace std;

//Stable : on? dinh.
// template <class T>
// void bubbleSort(vector<T> &data) {
//     int size = data.size();
//     for (int i = size - 1; i > 0; i--) {
//         int j = 0;
//         while (j < i) {
//             if (data[j] > data[j + 1]) {
//                 swap(data[j], data[j + 1]);
//             }
//             j++;
//         }
//     }
// }

// 2-1-4-5-3
template <class T>
void bubbleSort(vector<T> &data) {
    int size = data.size();
    for(int i = size-1;i>0;i--){
        for(int j = 0;j<i;j++){
            if(data[j] > data[j+1]){
                swap(data[j],data[j+1]);
            }
        }
    }
}

/* Testing */

int main() {
    srand(time(0));
    vector<int> data;

    data = generateVector(25);
    bubbleSort(data);
    printContainer(data);
    cout << "\n";

    auto stableData = getUnsortedStableData();
    bubbleSort(stableData);
    printSortData(stableData);

    return 0;
}
