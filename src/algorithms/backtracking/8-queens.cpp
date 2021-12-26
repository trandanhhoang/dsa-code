#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
// with n<=4, all have solution

#define ROW 8
#define COL 8
int sum = 0;

void print(vector<int> board) {

      for (int i = 0; i < ROW; i++) {
        cout << "|";
        for (int j = 0; j < COL; j++) {
            if (board[i] == j)
                cout << setw(2) << "Q"


                     << "|";
            else
                cout << setw(2) << " "
                     << "|";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

//8 huong.
bool check(vector<int> &board, int new_col, int old_row) {
    for (int new_row = 0; new_row < ROW; new_row++) {
        if (board[new_row] == new_col)
            return false;  // bat ki hang nao da~ co' cot
        if (abs(new_row - old_row) == abs(new_col - board[new_row]))
            return false;  // hang cheo'
    }
    return true;
}

void place_queen(vector<int> &board, int i_place) {
    // finish board
    if (i_place == ROW) {
        print(board);
        sum++;
        return;
    }
    // check to place new_queen by COL
    for (int i = 0; i < COL; i++) {
        if (check(board, i, i_place)) {
            board[i_place] = i;
            place_queen(board, i_place + 1);
            board[i_place] = -10;  // if fail
        }
    }
}

int main() {
    vector<int> board(ROW, -10);
    place_queen(board, 0);
    cout << " Count sum = " << sum << "\n";
}
