#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> arr;
    arr = vector<int>(nums.size(),1);
    int sizeArr = nums.size();
    int maxResult = 0;
    for (int i = 0; i < sizeArr; i++) {
        for (int j = i + 1; j < sizeArr; j++) {
            if (nums[i] < nums[j]) {
                arr[j] = max<int>(arr[j], arr[i] + 1);
            }
        }
        maxResult = max<int>(maxResult, arr[i]);
    }
    cout<<"hehe";
    return maxResult;
}


int main() {
    vector<int> nums = {2,1,9,7,0,8,3,10};

    cout << lengthOfLIS(nums);
}