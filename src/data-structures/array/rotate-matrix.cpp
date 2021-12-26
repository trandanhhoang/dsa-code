#include "matrix.h"

using namespace std;
// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15 16
// Rotate 90 degree clockwise

// 13  9  5  1
// 14  10 6  2
// 15  11 7  3
// 16  12 8  4
void swap(int &a, int &b) {
    int c;
    c = a;
    a = b;
    b = c;
}

void rotate90Clockwise(Matrix &matrix) {
    // TODO
    int row = matrix.size();
    int col = matrix[0].size();

    // for (int i = 0; i < row; i++) {
    //     for (int j = i; j < col; j++) {
    //         swap(matrix[i][j], matrix[j][i]);
    //     }
    // }
    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col / 2; j++) {
    //         swap(matrix[i][j], matrix[i][row - j - 1]);
    //     }
    // }

    for (int i = 0; i < row; i++) {
        for (int j = i; j < col; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col / 2; j++) {
            swap(matrix[i][j], matrix[i][col - j - 1]);
        }
    }
}

void rotate90CounterClockwise(Matrix &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = col - i - 1; j >= 0; j--) {
            swap(matrix[i][j], matrix[row - j - 1][row - 1 - i]);
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col / 2; j++) {
            swap(matrix[i][j], matrix[i][row - j - 1]);
        }
    }
}

void rotate180(Matrix &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row / 2; i++) {
        for (int j = 0; j < col; j++) {
            swap(matrix[i][j], matrix[row - i - 1][row - j - 1]);
        }
    }
}

int main() {
    int n = 4;
    Matrix matrix = createSquareMatrix(n);
    printMatrix(matrix);

    cout << "Rotate 90 degree clockwise\n";
    rotate90Clockwise(matrix);
    printMatrix(matrix);
    cout << "\n";

    cout << "Rotate 90 degree counter-clockwise\n";
    rotate90CounterClockwise(matrix);
    printMatrix(matrix);
    cout << "\n";

    cout << "Rotate 180 degree\n";
    rotate180(matrix);
    printMatrix(matrix);
    cout << "\n";

    return 0;
}
