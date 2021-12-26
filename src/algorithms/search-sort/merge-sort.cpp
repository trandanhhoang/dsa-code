#include "my-lib.h"
#include "sort.h"

using namespace std;

//0-1-2-3 -> (0,0,1)
template <class T>
void merge(vector<T> &data, int i_left, int e_left, int e_right)
{
    int i_right = e_left + 1;
    int i_left_2nd = i_left; // cause i_left ++ when insert into new_data
    vector<T> new_data;

    for (int i = i_left; i <= e_right; i++)
    {
        //4condition
        if (i_left > e_left)
        {
            new_data.emplace_back(data[i_right++]);
        }
        else if (i_right > e_right)
        {
            new_data.emplace_back(data[i_left++]);
        }
        else if (data[i_left] <= data[i_right])
        {
            new_data.emplace_back(data[i_left++]);
        }
        else
        {
            new_data.emplace_back(data[i_right++]);
        }
    }

    auto it = new_data.begin();
    for (int i = i_left_2nd; i <= e_right; i++)
    {
        data[i] = *(it++);
    }
}

// template <class T>
// //0-1-2-3-4
// void merge_h(vector<T> &data, int left, int right)
// {
//     // TODO
//     if (left == right)
//         return;

//     int middle = (left + right) / 2;
//     merge_h(data, left, middle);
//     merge_h(data, middle + 1, right);
//     int leftEnd = left + (right - left) / 2;
//     merge(data, left, leftEnd, right);
// }

// template <class T>
// void mergeSort(vector<T> &data)
// {
//     //TODO
//     merge_h(data, 0, data.size() - 1);
// }

template <class T>
//0-1-2-3-4
void merge_h(vector<T> &data, int left, int right)
{
    //condition to stop
    if (left >= right)
        return;
    int middle = (left + right) / 2;
    merge_h(data, left, middle);
    merge_h(data, middle + 1, right);
    //call merge, ileft,eleft,eright
    merge(data, left, middle, right);
}

// template <class T>
// void mergeSort(vector<T> &data)
// {
    // merge_h(data, 0, data.size() - 1);
// }

template <class T>
void mergeOfHelper(vector<T> &data,int leftPart1,int leftPart2,int sizePart){
    vector<T> newData;
    int leftSwap = leftPart1;
    int rightPart1 = leftPart1+sizePart;
    int rightPart2 = leftPart2+sizePart < data.size() ? leftPart2+sizePart : data.size();
    while(leftPart1 < rightPart1 || leftPart2 < rightPart2){
        if(leftPart1 == rightPart1){
            while(leftPart2 < rightPart2){
                newData.push_back(data[leftPart2++]);
            }
            break;
        }
        if(leftPart2 == rightPart2){
            while(leftPart1 < rightPart1){
                newData.push_back(data[leftPart1++]);
            }
            break;
        }
        if(data[leftPart1] <= data[leftPart2]){
            newData.push_back(data[leftPart1++]);
        }
        else{
            newData.push_back(data[leftPart2++]);
        }
    }
    for(int i = 0;i < newData.size();i++){
        data[leftSwap++] = newData[i];
    }
}

template <class T>
void helper(vector<T> &data,int size){
    int lengthOfData = data.size()-1;
    if(size/2 > lengthOfData ){
        return;
    }
    int left=0;
    while(left<lengthOfData){
        mergeOfHelper(data,left,left+size/2,size/2);
        left = left + size;
    }
    helper(data,size*2);
}


template <class T>
void mergeSort(vector<T> &data)
{
    helper(data,2);
}


int main()
{
    srand(time(0));
    vector<int> data;
    data = generateVector(25);
    printContainer(data);
    cout << "\n";
    mergeSort(data);
    printContainer(data);
    cout << "\n";

    auto stableData = getUnsortedStableData();
    mergeSort(stableData);
    printSortData(stableData);

    return 0;
}
