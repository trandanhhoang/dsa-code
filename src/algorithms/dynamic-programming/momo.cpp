#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int foo(vector<int> input){
    int length = input.size();
    int counter = 0;
    int maxLength = 0;
    for(int i =0;i<length;i++){
        int start = input[i];
        for(int j =i+1;j<length;j++){
            counter++;
            start = start + input[j];
            if(start == 0 && maxLength < counter){
                maxLength = counter+1;
            }
        }
        counter = 0;
    }
    return maxLength;
}

int main(){

    vector<int> input = {15, -2, 2, -8, 1, 7,2,-2, 10, 23};
    cout << foo(input);
}
