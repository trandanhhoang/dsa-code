#include<iostream>
#include<vector>

using namespace std;

//1 - 2 - 6 - 5

void countingSort(vector<int> &data){
    // TODO
    // Create new vector
    vector<int> i_store(10,0);
    vector<int> new_data(data.size());

    // save the count of each element
    for(int i =0;i<data.size();i++){
        i_store[data[i]]++;
    }
    // add on from left to right ( cong. don`)
    for(int i = 1;i<i_store.size();i++){
        i_store[i] = i_store[i] + i_store[i-1]; 
    }
    
    //Counting sort
    for(int i = data.size()-1;i >= 0;i--){
        auto number = data[i];
        new_data[i_store[number]-1] = number;
        i_store[number]-=1;
    }
    
    for(int i = 0; i<data.size();i++) {
        cout<<new_data[i]<<" ";
    }

}

int main() {
    srand(time(0));
    vector<int> data;

    // data = generateVector(25);
    data.emplace_back(7);
    data.emplace_back(1);
    data.emplace_back(5);
    data.emplace_back(1);
    data.emplace_back(3);
    data.emplace_back(4);
    data.emplace_back(2);
    data.emplace_back(6);
    data.emplace_back(6);
    data.emplace_back(8);
    data.emplace_back(6);
    data.emplace_back(9);
    data.emplace_back(9);
    data.emplace_back(0);

    for(int i =0;i<data.size();i++){
        cout<< data[i]<<" ";
    }
    cout<<"\n";
    countingSort(data);
    return 0;
}
