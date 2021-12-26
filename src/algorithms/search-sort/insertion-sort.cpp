#include "my-lib.h"
#include "sort.h"

using namespace std;
//STABLE
// 5-2-1-3
// chon 2 => 2-5-1-3
// chon 1 => 1-2-5-3

//best case : O (n)

// template <class T>
// void insertionSort(vector<T> &data) {
//     int size = data.size();
//     for(int i = 1;i < size;i++){
//         int j = i;
//         while(j>0 && data[j-1]>data[j]){
//             swap(data[j],data[j-1]);
//             j--;
//         }
//     }
// }
template <class T>
void insertionSort(vector<T> &data) {
    int size = data.size();
    for(int i = 1;i<size;i++){
        for(int j = i;j>0;j--){
            if(data[j-1]>data[j]){
                swap(data[j],data[j-1]);
            }else{
                break;
            }
        }
    }
}

int main() {
    srand(time(0));
    vector<int> data;

    data = generateVector(25);
    insertionSort(data);
    printContainer(data);
    cout << "\n";

    auto stableData = getUnsortedStableData();
    insertionSort(stableData);
    printSortData(stableData);

    return 0;
}
