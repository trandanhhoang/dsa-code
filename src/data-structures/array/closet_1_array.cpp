#include "my-lib.h"

using namespace std;

/*
 * Find one pair of elements that sum is closest to target
 */
// Complexity O(n^2) time, O(1) Space
pair<int, int> closestPair(vector<int> &data, int target) {  //Brutal Force with 2 For
    // TODO
    pair<int, int> ret;

    int shift = INT32_MAX;
    int size = data.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = i; j < size; j++) {
            if (abs(data[i] + data[j] - target) < shift) {
                shift = abs(data[i] + data[j] - target);
                ret.first = data[i];
                ret.second = data[j];
            }
        }
    }
    return ret;
}
// Complexity O(nlogn) time for sort, O(1) Space
pair<int, int> closestPairSort(vector<int> &data, int target) {  //Sort
    // TODO
    pair<int, int> ret;
    int shift = INT32_MAX;
    int size = data.size();

    sort(data.begin(), data.end());
    int left = 0, right = size - 1;
    while (left < right) {
        if (abs(data[left] + data[right] - target) < shift) {
            shift = abs(data[left] + data[right] - target);
            ret.first = data[left];
            ret.second = data[right];
        }
        if (data[left] + data[right] == target) {
            ret.first = data[left];
            ret.second = data[right];
            return ret;
        } else if (data[left] + data[right] > target) {
            right--;
            continue;
        } else {
            left++;
            continue;
        }
    }
    return ret;
}

int main() {
    vector<int> data = {27, 26, 40, 35, 30, 26, 28, 24};  // Expect (26, 23)
    int target = 50;
    // auto elePair = closestPair(data, target);
    auto elePair = closestPairSort(data, target);
    cout << "(" << elePair.first << "," << elePair.second << ")\n";

    return 0;
}
