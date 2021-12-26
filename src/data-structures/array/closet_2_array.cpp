#include "my-lib.h"

using namespace std;

/*
 * Given two array, find the pair from EACH array that sum is closest to target
 */
// Complexity O(n^2) time , O(1) space
pair<int, int> closestPair(vector<int> &data1, vector<int> &data2, int target) {//Brutal Force
    // TODO
    int size1=data1.size(),size2=data2.size();
    int shift =INT32_MAX;
    pair<int,int> ret;

    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
            if(abs(data1[i]+data2[j]-target) < shift){
                shift = abs(data1[i]+data2[j]-target);
                ret.first = data1[i];
                ret.second = data2[j];
            }
        }
    }
    return ret;
}
// Complexity Sort Time , O(1) space
pair<int, int> closestPairSort(vector<int> &data1, vector<int> &data2, int target) {//Sort 2 array, array1 go right, array2 go left
    // TODO
    int size1=data1.size(),size2=data2.size();
    int shift =INT32_MAX;

    sort(data1.begin(),data1.end());
    sort(data2.begin(),data2.end());

    pair<int,int> ret;
    int left=0,right=size2-1;
    while(left!=size1-1 && right != 0){
        int hehe = abs(data1[left]+data2[right]-target);
        if(abs(data1[left]+data2[right]-target) < shift){
            shift = abs(data1[left]+data2[right]-target);
            ret.first = data1[left];
            ret.second = data2[right];
        }
        if(abs(data1[left]+data2[right]) == target){
            return ret;
        }
        else if(abs(data1[left]+data2[right]) < target){
            left++;
            continue;
        }
        else{
            right--;
            continue;
        }
    }
    
    return ret;
}

int main() {
    vector<int> data1 = {-2, 10, 3, 20, -5, 9, 10};
    vector<int> data2 = {4, 5, 7, -4, 15, 18, 7, -3, 6};
    int target = 20;  // Expect 3 from first array and 18 from second array

    auto elePair = closestPairSort(data1, data2, target);
    cout << "(" << elePair.first << "," << elePair.second << ")\n";

    return 0;
}