#include "tower-of-hanoi.h"

using namespace std;

//case 1 : reverse.
//case 2 : stack => dung stack de? khu? de. quy

/* Core algorithm */
// void towerOfHanoi(int n, char src, char dst, char aux, TowerOfHanoi &tower) {
//     // TODO (remember to print step)
//     tower.print();
//     if (n == 0) return;

//     towerOfHanoi(n - 1, src, aux, dst, tower);
//     tower.move(src, dst);
//     towerOfHanoi(n - 1, aux, dst, src, tower);
// }

void towerOfHanoi(int n, char src, char dst, char aux, TowerOfHanoi &tower) {
    tower.print();
    if(n==0){
        return;
    }

    towerOfHanoi(n-1,src,aux,dst,tower);
    tower.move(src,dst);
    // towerOfHanoi(1,src,dst,aux,tower);
    towerOfHanoi(n-1,aux,dst,src,tower);
}

int main() {
    int numOfDisks = 5;
    char src = 'A', dst = 'C', aux = 'B';
    TowerOfHanoi tower(numOfDisks, {src, aux, dst}, src);

    cout << "Start\n";
    tower.print();
    towerOfHanoi(numOfDisks, src, dst, aux, tower);
    cout << "Finish!\n";

    return 0;
}
