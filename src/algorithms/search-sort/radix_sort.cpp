#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1 - 2 - 6 - 5
int getMax(vector<int> data){
    int max = INT32_MIN;
    for(int i = 0; i<data.size();i++){
        if(data[i]>max){
            max =data[i];
        }
    }
    return max;
}
void swapVector(vector<int> &data,vector<int> &new_data){
    for(int i =0;i<data.size();i++){
        data[i] = new_data[i];
    }
}

void countingSort(vector<int> &data,int place){
    // TODO
    // Create new vector
    vector<int> i_store(10,0);
    vector<int> new_data(data.size());

    // save the count of each element
    for(int i =0;i<data.size();i++){
        int number = (data[i] - (data[i]/(place*10)*place*10))/place;
        if(data[i]<place) number = 0;
        i_store[number]++;
    }
    // add on from left to right ( cong. don`)
    for(int i = 1;i<i_store.size();i++){
        i_store[i] = i_store[i] + i_store[i-1]; 
    }
    //Counting sort
    for(int i = data.size()-1;i >= 0;i--){
        int number = (data[i] - (data[i]/(place*10)*place*10))/place;
        if(data[i]<place) number = 0;

        new_data[i_store[number]
        -1] = data[i];
        i_store[number]-=1;
    }

    swapVector(data,new_data);   
}

void radixSort(vector<int> &data){
    // TODO
    int maxNumber =  *max_element(data.begin(),data.end());
    cout<< maxNumber <<"\n";
    // int maxNumber = getMax(data);
    for(int i = 1;i<maxNumber;i*=10){
        countingSort(data,i);
    }

}

//least difinigcation ... -> tu phai? qua

// most difinigcation ...

int main() {
    srand(time(0));
    vector<int> data;

    // data = generateVector(25);
    data.emplace_back(170);
    data.emplace_back(45);
    data.emplace_back(75);
    data.emplace_back(90);
    data.emplace_back(802);
    data.emplace_back(24);
    data.emplace_back(2);

    for(int i =0;i<data.size();i++){
        cout<< data[i]<<" ";
    }
    cout<<"\n";
    radixSort(data);
    for(int i =0;i<data.size();i++){
        cout<< data[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
