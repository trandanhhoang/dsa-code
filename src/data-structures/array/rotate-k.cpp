#include "my-lib.h"

using namespace std;

// 1 2 3 4 5 6 7 8 9 10 11 12
// 5 6 7 8 9 10 11 12 1 2 3 4 k = 4

//o(1) space + time = n, O(n^2) time
void rotateLeft(vector<int> &data, int k) {
    // TODO
    // k > n => mod
    int store, size = data.size();
    k = k % size;
    // if k< 0
    if (k < 0) k = size + k;
    //12345 - k=2 - 45123
    for (int j = 0; j < k; j++) {
        store = data[0];
        for (int i = 0; i < size; i++) {
            data[i] = data[i + 1];
        }
        data[size - 1] = store;
    }
}
void swap(int &a, int &b) {
    int c;
    c = a;
    a = b;
    b = c;
}

// 1 2 3 4 5 6  7  8  9  10 11 12 13
// 5 6 7 8 9 10 11 12 13 1  2  3  4  k = 4
// Complexity: O(1) space O(n) time.
void rotateLeftWithoutLoop(vector<int> &data, int k) {
    // TODO
    int store, size = data.size();
    k = k % size;
    if (k < 0) k = size + k;
    for (int j = 0; j < k / 2; j++) {
        swap(data[j], data[k - j - 1]);
    }
    for (int j = 0; j < (size - k) / 2; j++) {
        swap(data[k + j], data[size - j - 1]);
    }
    for (int j = 0; j < (size) / 2; j++) {
        swap(data[j], data[size - j - 1]);
    }
}

void rotateRight(vector<int> &data, int k) {
    // TODO
    int store, size = data.size();
    for (int j = 0; j < k; j++) {
        store = data[size - 1];
        for (int i = size - 1; i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[0] = store;
    }
}

int main() {
    int size = 13;
    int k = 4;

    vector<int> init;
    for (int i = 0; i < size; i++) {
        init.emplace_back(i + 1);
    }
    printContainer(init);
    cout << "\n";

    vector<int> data;
    cout << "Rotate left by k = " << k << "\n";
    data = init;
    rotateLeftWithoutLoop(data, k);
    printContainer(data);
    cout << "\n";

    cout << "Rotate right by k = " << k << "\n";
    data = init;
    rotateRight(data, k);
    printContainer(data);
    cout << "\n";

    return 0;
}
