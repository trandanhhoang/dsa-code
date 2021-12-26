#include <stack>

#include "my-lib.h"
using namespace std;

//c1: sort -> find O(nlog)
int firstPositiveMissing1(vector<int> &data) {
    sort(data.begin(), data.end());
    int firstMissing = 1;

    for (auto &element : data) {
        if (element > 0) {
            if (element == firstMissing - 1) {
                continue;
            }
            if (element != firstMissing) {
                return firstMissing;
            }
            firstMissing++;
        }
    }
    return firstMissing;
}
//c2: new vector with index
int firstPositiveMissingWithVector(vector<int> &data) {
    // vector<int> data = {2, 3, -7, 6, 8, 1, -10, 15};  // Expect 4
    int size = data.size();
    vector<int> my_vector(size, 0);

    for (auto &&i_data : data) {
        if (i_data > 0 && i_data < size) {
            my_vector[i_data - 1] = 1;
        }
    }

    for (int i = 0; i < size; i++) {
        if (my_vector[i] == 0)
            return i + 1;
    }
    return size + 1;
}
//c3: new array with index O(n) time + O(n) space
int firstPositiveMissingWithArray(vector<int> &data) {
    // TODO
    // vector<int> data = {2, 3, -7, 6, 8, 1, -10, 15};  // Expect 4
    int size = data.size();
    int arr[size] = {0};
    //1,2,3,4
    //  why err ?
    for (auto &&i_data : data) {
        if (i_data > 0) {
            if (i_data < size) {
                arr[i_data - 1] = 1;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0)
            return i + 1;
    }
    return data.size() + 1;
}
//c4: O(n) time + O(1) space
int firstPositiveMissingOptimal(vector<int> &data) {
    // if negative -> assign = 0. ex: 2 -3 2 -6 -> 2 0 2 6
    for (auto &i_data : data) {
        if (i_data < 0) {
            i_data = 0;
        }
    }
    int size = data.size();
    // negative + abs
    for (int i = 0; i < size; i++) {
        if (abs(data[i]) > 0 && abs(data[i]) < size) {  //
            if (data[abs(data[i]) - 1] > 0)             // condition: if negative,continue
            {
                data[abs(data[i]) - 1] = -data[abs(data[i]) - 1];
            }
        }
    }

    //return output
    for (int i = 0; i < size; i++) {
        if (data[i] > 0) {
            return i + 1;
        }
    }
    return size + 1;
}

int main() {
    //{2, 3, -7, 6, 8, 1, -10, 15} expect 4
    //{2, 3, 7, 6, 8, -1, -10, 15} expect 1
    //{1, 1, 0, -1, -2} expect 2
    //1,2,3,3,5,4} exxpect 6
    vector<int> data = {0, 2, 3, 3, 3, 3, 3, 5, 4};  // Expect 6
    cout << firstPositiveMissingOptimal(data);

    return 0;
}
