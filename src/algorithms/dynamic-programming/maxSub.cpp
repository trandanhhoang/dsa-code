#include <iostream>
#include <vector>

using namespace std;

vector<int> arr(10000, 1);

//[10,9,2,5,3,7,101,18]
int lengthOfLIS(vector<int>& nums) {
    int sizeArr = nums.size();
    int maxResult = 0;
    for (int i = 0; i < sizeArr; i++) {
        for (int j = i + 1; j < sizeArr; j++) {
            if (nums[i] < nums[j]) {
                arr[j] = max<int>(arr[j], arr[i] + 1);
            }
        }
        cout << arr[i] << endl;
        maxResult = max<int>(maxResult, arr[i]);
    }
    return maxResult;
}

int main() {
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(8);
    arr.push_back(7);
    arr.push_back(9);

    cout << lengthOfLIS(arr);
}
