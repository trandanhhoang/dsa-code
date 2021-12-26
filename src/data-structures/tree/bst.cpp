#include "bst.h"

#include <vector>

using namespace std;

/*

Insert: 5 6 2 1 4 3 7

            5
          /  \
        2     6
      /  \     \
    1     4     7
        /
      3

Delete: 6 2 5 7 3 4 1

            5
          /  \
        2     7
      /  \
    1     4
        /
      3

            5
          /  \
        3     7
      /  \
    1     4

            7
          /
        3
      /  \
    1     4


            3
          /  \
        1     4

            4
          /
        1

            1

*/

int main() {
    BST bst;

    /* Insert */

    for (auto &&ele : {5, 6, 2, 1, 4, 3, 7}) {
        bst.insert(ele);
    }

    bst.inorder(print);
    bst.preorder(print);
    bst.postorder(print);
    bst.levelOrder();
    cout << "\nHeight: " << bst.getHeight() << "\n";
    cout << "Number of nodes: " << bst.countNodes() << "\n";
    cout << "Number of leaf nodes: " << bst.countLeafNodes() << "\n";
    cout << "Max: " << bst.findMax() << "\n";
    cout << "Min: " << bst.findMin() << "\n";
    cout << "Search for 3: " << boolalpha << bst.search(3) << "\n";
    cout << "Search for 10: " << boolalpha << bst.search(10) << "\n";
    cout << "\n";

    // /* Delete */

    for (auto &&ele : {6, 2, 5, 7, 3, 4, 1}) {
        cout << "Delete " << ele << "\n";
        bst.remove(ele);
        bst.preorder(print);
        cout << "\n";
    }

    return 0;
}
