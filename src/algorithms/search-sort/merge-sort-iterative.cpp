#include <stack>
#include <tuple>

#include "my-lib.h"
#include "sort.h"

using namespace std;

template <class T>
void merge(vector<T> &data, int left, int endLeft, int endRight)
{
    //new variable to solve
    int iLeft = left;
    int iRight = endLeft;
    vector<T> new_data;
    //loop with 4 conditions
    for (int i = left; i < endRight; i++)
    {
        if (iLeft >= endLeft)
        {
            new_data.push_back(data[iRight]);
            iRight++;
        }
        else if (iRight >= endRight)
        {
            new_data.push_back(data[iLeft]);
            iLeft++;
        }
        else if (data[iLeft] <= data[iRight])
        {
            new_data.push_back(data[iLeft]);
            iLeft++;
        }
        else
        {
            new_data.push_back(data[iRight]);
            iRight++;
        }
    }
    //assign for old_data
    for (auto e_data : new_data)
    {
        data[left++] = e_data;
    }
}

template <class T>
void mergeSortIterative(vector<T> &data)
{
    //loop to merge bottum up, no recursive
    int length = data.size();
    //loop for step
    for (int step = 1; step < length; step *= 2)
    {
        //loop to traversal
        for (int left = 0; left < length; left += step * 2)
        {
            //call merge
            int endLeft = left + step;
            int endRight = min<int>(left + 2 * step, length);
            merge(data, left, endLeft, endRight);
        }
    }
}

int main()
{
    srand(time(0));
    vector<int> data;

    data = generateVector(32);
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
    cout << "\n";
    mergeSortIterative(data);
    printContainer(data);
    cout << "\n";

    auto stableData = getUnsortedStableData();
    mergeSortIterative(stableData);
    printSortData(stableData);

    return 0;
}
