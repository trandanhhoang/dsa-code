#include <iostream>
#include <vector>

using namespace std;
#define ROW 9
#define COL 9

vector<vector<int>> sudoku(ROW);
void print() {
    for (int i = 0; i < ROW; i++) {
        if (i % 3 == 0) cout << "____________________\n";
        for (int j = 0; j < COL; j++) {
            if (j % 3 == 0) cout << "|";
            cout << sudoku[i][j] << " ";
        }

        cout << "\n";
    }
}

bool check(int row, int col, int value) {  // don't duplicate in row, col, a mini board.
    //row && col
    for (int i = 0; i < ROW; i++) {
        if (sudoku[row][i] == value || sudoku[i][col] == value)
            return false;
    }
    //mini board
    for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++) {
        for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++) {
            if (sudoku[i][j] == value) return false;
        }
    }
    return true;
}

void solve(int row, int col) {
    // condition top: index = row*col = 81
    if (row == ROW) {
        print();
        cout << endl;
        return;
    }
    //loop with backtrack
    // if filled
    if (sudoku[row][col] > 0) {
        if (col == COL - 1) {
            row++;
            col = -1;
        }
        col++;
        solve(row, col);
    } else {  // brutal force
        for (int i = 1; i < 10; i++) {
            if (check(row, col, i) && sudoku[row][col] == 0) {
                sudoku[row][col] = i;
            }
            if (sudoku[row][col] > 0) {
                int test_row = row, test_col = col;
                if (test_col == COL - 1) {
                    test_row++;
                    test_col = -1;
                }
                test_col++;
                solve(test_row, test_col);
                sudoku[row][col] = 0;
            }
        }
    }
}

int main() {
    for (int i = 0; i < ROW; i++) {
        vector<int> col(COL);
        sudoku[i] = col;
    }
    // INIT BOARD.

    sudoku[0][1] = 3;
    sudoku[0][4] = 7;
    sudoku[0][7] = 5;

    sudoku[1][0] = 5;
    sudoku[1][3] = 1;
    sudoku[1][5] = 6;
    sudoku[1][8] = 9;

    // 5 0 0   1 0 6   0 0 9
    // 0 3 0   0 7 0   0 5 0
    // 0 0 1   0 0 0   4 0 0

    // 0 9 0   0 5 0   0 6 0
    // 6 0 0   4 0 2   0 0 7
    // 0 4 0   0 1 0   0 3 0

    // 0 0 2   0 0 0   8 0 0
    // 9 0 0   3 0 5   0 0 2
    // 0 1 0   0 2 0   0 7 01

    sudoku[2][2] = 1;
    sudoku[2][5] = 4;
    sudoku[2][7] = 5;

    sudoku[3][0] = 8;
    sudoku[3][1] = 7;
    sudoku[3][3] = 4;
    sudoku[4][0] = 2;
    sudoku[4][2] = 6;
    sudoku[4][4] = 8;
    sudoku[4][8] = 3;
    sudoku[5][2] = 9;
    sudoku[5][6] = 8;
    sudoku[6][1] = 3;
    sudoku[6][7] = 8;
    sudoku[6][8] = 5;
    sudoku[7][3] = 6;
    sudoku[8][2] = 4;
    sudoku[8][6] = 2;
    sudoku[8][7] = 1;

    // print();
    // solve(0,0);
    print();

    return 0;
}
