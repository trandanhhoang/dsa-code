//DONE
#include "sll.h"

using namespace std;


// POINTER TO POINTER SLL
// int main(){
//     SLL sll;
//     sll.pushFront(2);
//     sll.pushFront(1);
//     sll.traverse();

//     sll.insertAtP2p(0, 4);
//     sll.insertAtP2p(2, 3);
//     sll.insertAtP2p(0, 15);
//     sll.insertAtP2p(1, 9);
//     sll.traverse();
// }


int main() {
    SLL sll;
    sll.pushFront(2);
    sll.pushFront(1);
    
    sll.traverse();

    sll.insertAt(2, 4);
    sll.insertAt(2, 3);
    sll.insertAt(0, 15);
    sll.insertAt(1, 9);

    sll.traverse();

    /* Search */
    cout << "Search for 4: " << boolalpha << sll.search(4) << "\n";
    cout << "Search for 5: " << boolalpha << sll.search(5) << "\n";
    cout << "\n";

    /* Delete */
    cout << "Remove all elements\n";
    sll.removeAt(2);
    sll.traverse();

    sll.remove(1);
    sll.remove(3);
    sll.popFront();
    sll.traverse();
    cout << "\n";

    /* Iterator */
    sll.pushFront(4);
    sll.pushFront(3);
    sll.pushFront(2);
    sll.pushFront(1);
    sll.traverse();

    // cout<<"clear "<<endl;
    // sll.clear();
    // sll.traverse();

    cout << "Increase all elements by one\n";
    auto it = sll.begin();
    while (it != sll.end()) {
        (*it++)++;
    }
    sll.traverse();

    return 0;
}

