#include "heap.h"

using namespace std;

/*

Input: 0 4 3 5 8 2 1 6 7 9

Unoptimized construction:

                    0

                    4
                  /
                0

                    4
                  /  \
                0     3

                    5
                  /  \
                4     3
              /
            0

                    8
                  /  \
                5     3
              /  \
            0     4

                      8
                    /  \
                  /     \
                5        3
              /  \     /
            0     4  2

                      8
                    /  \
                  /     \
                5        3
              /  \     /  \
            0     4  2     1

                      8
                    /  \
                  /     \
                6        3
              /  \     /  \
            5     4  2     1
          /
        0

                      8
                    /  \
                  /     \
                7        3
              /  \     /  \
            6     4  2     1
          /  \
        0     5

                      9
                    /  \
                  /     \
                /        \
              8           3
            /  \        /  \
          /     \     /     \
        6        7  2        1
      /  \     /
    0     5  4

*/

/*

Input: 0 4 3 5 8 2 1 6 7 9

Bottom-up construction:

                      0
                    /  \
                  /     \
                /        \
              4           3
            /  \        /  \
          /     \     /     \
        5        8  2        1
      /  \     /
    6     7  9      

                      0
                    /  \
                  /     \
                /        \
              4           3
            /  \        /  \
          /     \     /     \
        5        9  2        1
      /  \     /
    6     7  8

                      0
                    /  \
                  /     \
                /        \
              4           3
            /  \        /  \
          /     \     /     \
        7        9  2        1
      /  \     /
    6     5  8

                      0
                    /  \
                  /     \
                /        \
              9           3
            /  \        /  \
          /     \     /     \
        7        8  2        1
      /  \     /
    6     5  4

                      9
                    /  \
                  /     \
                /        \
              8           3
            /  \        /  \
          /     \     /     \
        7        4  2        1
      /  \     /
    6     5  0

*/

int main() {
    vector<int> init({0, 4, 3, 5, 8, 2, 1, 6, 7, 9});

    // // Unoptimized construction
    cout << "Build heap in O(nlogn):\n";
    vector<int> heapUnoptimized = buildHeapUnoptimized(init);
    print(heapUnoptimized);
    cout << "\n";

    // Bottom-up construction
    cout << "Build heap in O(n):\n";
    vector<int> heap = init;
    buildHeap(heap);
    print(heap);

    return 0;
}
