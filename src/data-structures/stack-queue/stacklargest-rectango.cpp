#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
    int max_height = heights.size();
    stack<int> stack_positions;
    stack<int> stack_heights;
    // TODO
    int largest_area = INT32_MIN;

    for(int i=0;i<max_height ;i++){
        int current_height = heights[i];
        int position_current_height = i;

        while(stack_heights.size()>0 && current_height<stack_heights.top()){
            int larger = stack_heights.top();
            stack_heights.pop();
            position_current_height = stack_positions.top();
            stack_positions.pop();
            int size_of_larger = larger * (i-position_current_height);
            if(size_of_larger>largest_area){
                largest_area = size_of_larger;
            }
        }
        if(stack_heights.size()>0 && current_height==stack_heights.top()){
            continue;
        }

        stack_heights.push(current_height);
        stack_positions.push(position_current_height);
    }

    while(stack_heights.size()>0){
        int larger = stack_heights.top();
        stack_heights.pop();
        int position_of_larger = stack_positions.top();
        stack_positions.pop();
        int size_of_larger = larger * (max_height-position_of_larger);
        if(size_of_larger>largest_area){
            largest_area = size_of_larger;
        }
    }

    return largest_area;
}

int main() {
    vector<vector<int>> test;
    test.push_back(vector<int> ({2,1,1,2}));  // Expect 4
    // test.push_back(vector<int> ({2,1,5,6,2,3}));  // Expect 10
    // test.push_back(vector<int> ({2,4}));  // Expect 4
    for(int i=0;i<test.size();i++){
        cout << largestRectangleArea(test[i]) << "\n";
    }
    return 0;
}

/*
stack<int> my_stack;
    stack<int> cp_stack;
    int length = heights.size();
    int max = -1;
    int size;
    for (auto &key : heights) {
        size = 1;
        cp_stack = my_stack;
        int realkey = key;

        while (!cp_stack.empty()) {
            if (cp_stack.top() >= realkey) {
                cp_stack.pop();
                size++;
            } else {
                if (max < size * realkey) {
                    max = size * realkey;
                }
                realkey = cp_stack.top();
                cp_stack.pop();
                size++;
            }
        }
        my_stack.push(key);
    }
    return max;*/
