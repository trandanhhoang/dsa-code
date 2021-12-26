//DONE
#include <stack>

#include "my-lib.h"
using namespace std;
// Time Complexity O(n^2) with 2 loop
vector<int> allNextGreaters(vector<int> data) {
    vector<int> nextGreaters;
    // TODO
    int size = data.size();
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (data[j] > data[i]) {
                nextGreaters.emplace_back(data[j]);
                break;
            }
            if (j == size - 1) {
                nextGreaters.emplace_back(-1);
            }
        }
    }
    return nextGreaters;
}
//O(n) time with stack
vector<int> allNextGreatersOptimize(vector<int> &data) {
    stack<int> my_stack;
    int size = data.size();
    int tail = size - 1;
    vector<int> my_vec(size);
    while (tail >= 0) {
        while (!my_stack.empty() && data[tail] >= my_stack.top()) {
            my_stack.pop();
        }
        if (my_stack.empty()) {
            my_vec[tail] = -1;
        } else {
            my_vec[tail] = my_stack.top();
        }
        my_stack.push(data[tail--]);
    }
    return my_vec;
}

int main() {
    vector<int> data = {10, 6, 7, 7, 8, 9};

    auto nextGreaters = allNextGreatersOptimize(data);  // Expect [-1, 8, 9, 9, -1]
    printContainer(nextGreaters);

    return 0;
}
