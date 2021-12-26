#include "my-lib.h"

using namespace std;

// int binarySearch(vector<int> &data, int value) {
//     int middle,left = 0, right = data.size()-1;
//     while(true){
//         middle = (left + right)/2;
//         if(data[middle] == value)
//             return middle;
//         else if(data[middle] > value){
//             right = middle;
//         }
//         else{
//             left = middle;
//         }
//         // no value in vector.
//         if(left == right-1) return -1;
//     }
// }

//1 2 3 5 6 7
// left = 2,right = 3. middle = 2.
//2-5 middle = 3
//2-3 left .
//1 2 3 4 5
//3-5 left =20 right = 21, middle= 20 || middle = 21
int binarySearch(vector<int> &data, int value) {
    int left = 0;
    int right = data.size()-1;
    int middle = (right + left)/2;
    while(left != right ){
        if(left==right-1 && left ==middle){
            return -1;
        }
        if(data[middle] < value){
            left = middle;
        }
        else if(data[middle] > value){
            right = middle;
        }
        else{
            return middle;
        }
        middle = (right + left)/2;
    }
    return -1;
}
int main() {
    srand(time(0));

    int maxSize = 50;
    auto data = generateSortedVector(maxSize);
    printVectorWithIndex(data);
    cout << "\n";

    for (int i = 1; i <= 5; i++) {
        int value = rand() % maxSize + 1;
        cout << "Index of " << setw(2) << value << " is "<<endl;
        cout<< binarySearch(data, value) << "\n";
    }

    return 0;
}
