#include "my-lib.h"
using namespace std;
#include<unordered_map>
/*
 * Count number of pairs that sum up to target
 */

int countTwoSum(vector<int> &data, int target) { // Brutal Force
    int sum=0;
    int size = data.size();
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(data[i]+data[j]==target){
                sum++;
            }
        }
    }
    return sum;
}

int countTwoSumHash(vector<int> &data, int target) { //UnOrderMap <=> hash
    int sum=0;
    int size = data.size();
    unordered_map<int,int> mymap;
    for(int i=0;i<size;i++){
        sum+=mymap[target-data[i]];
        mymap[data[i]]++;
    }

    return sum;
}

int countTwoSumSort(vector<int> &data, int target) { //Sort head tail move
    int sum=0;
    int size = data.size();
    
    sort(data.begin(),data.end());
    int left=0,right=size-1;
    int size_left=1,size_right=1;
    while(left<right){
        if(data[left]==data[left+1]){
            size_left++;
            left++;
            if(left==right){
                if(data[left]*2==target){
                    sum+= size_left*(size_left-1)/2;
                    break;
                }
            }
            continue;
        }
        //4+4=8
        if(data[right]==data[right-1]){
            size_right++;
            right--;
            continue;
        }

        if(target-data[left]<data[right]){
            size_right=1;
            right--;
            continue;
        }
        if(target-data[left]>data[right]){
            size_left=1;
            left++;
            continue;
        }
        if(target-data[left]==data[right]){
            sum+=size_left*size_right;
            size_left=1;
            size_right=1;
            left++;
            right--;
            continue;
        }
    }

    return sum;
}

int main() {
    vector<int> data = {1,1,1,7,7,5,5,5,5};
    int target = 8;
    cout << "brutal force: " << countTwoSum(data, target)<<"\n";
    cout << countTwoSumHash(data, target)<<"\n";
    cout << countTwoSumSort(data, target);
    return 0;
}