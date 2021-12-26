#include "my-lib.h"
using namespace std;

/*
 * Given array of n + 1 elements with 1 <= arr[i] <= n.
 * There's only one duplicated value, find that value.
 */

//o(n^2) time, brutal force
int findDuplicatedBrutalForce(vector<int> &data, int n)
{
    int size = data.size(), sum = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (data[i] == data[j])
            {
                sum++;
                ;
            }
        }
    }
    return sum;
}

//time = time sort
int findDuplicatedSort(vector<int> &data, int n)
{
    int size = data.size(), sum = 0, duplicate = 1;

    sort(data.begin(), data.end());

    for (int i = 0; i < size - 1; i++)
    {
        if (data[i] == data[i + 1])
        {
            duplicate++;
            continue;
        }
        if (data[i] != data[i + 1] && duplicate > 1)
        {
            sum = duplicate * (duplicate - 1) / 2;
            break;
        }
    }
    return sum;
}

//time O(n),space O(n),not change array
int findDuplicatedHash(vector<int> &data, int n)
{
    int size = data.size(), sum = 0, dup = 1;
    vector<int> my_vector(size, 0);
    for (int i = 0; i < size; i++)
    {
        if (my_vector[data[i]] == 1)
        {
            return data[i];            
        }
        my_vector[data[i]] = 1;
    }
    return -1;
}

// negative array O(1) space, O(n) time, not change array
int findDuplicatedOptimalSpace(vector<int> &data, int n)
{
    // TODO
    int size = data.size(), sum = 0, dup = 1;

    for (int i = 0; i < size; i++)
    {
        if (data[(abs(data[i]))] < 0)
        {
            return abs(data[i]);
        }
        data[abs(data[i])] = -data[abs(data[i])];
    }
    return 1;
}

// int check()

int findDuplicatedBin(vector<int> &data, int n)
{
    // TODO
    // binary search O(1) space, O(x) < O(n^2)  time, not change array
    int size = data.size();
    int left = 1, right = size;
    while (true)
    {
        int check = 0;
        if (left == right)
        {
            return left;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] <= (right + left) / 2)
            {
                check--;
            }
            if (data[i] > (right + left) / 2 && data[i] <= right)
            {
                check++;
            }
        }
        if (check < 0)
        {
            right = (right + left) / 2;
        }
        else
        {
            left = (right + left) / 2 + 1;
        }
    }
    return 1;
}

int main()
{
    int n = 9;
    vector<int> data = {3, 8, 2, 8, 5, 1, 3, 9, 7, 3, 4}; // Expect 3

    // cout << findDuplicatedBrutalForce(data, n)<<"\n";
    // cout << findDuplicatedSort(data, n)<<"\n";
    // cout << findDuplicatedHash(data, n)<<"\n";
    // cout << findDuplicatedOptimalSpace(data, n)<<"\n";
    cout << findDuplicatedHash(data, n) << "\n";

    return 0;
}
