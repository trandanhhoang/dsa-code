#if !defined(MATRIX_H)
#define MATRIX_H

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Matrix;

Matrix createMatrix(int row, int col) {
    Matrix matrix(row, std::vector<int>(col));
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = ++count;
        }
    }
    return matrix;
}

Matrix createSquareMatrix(int n) {
    return createMatrix(n, n);
}

void printMatrix(Matrix &matrix) {
    // Find padding
    int minEle = INT32_MAX, maxEle = INT32_MIN;
    for (auto &&row : matrix) {
        for (auto &&ele : row) {
            minEle = std::min(ele, minEle);
            maxEle = std::max(ele, maxEle);
        }
    }
    int maxAbs = std::max(abs(minEle), abs(maxEle));
    int padding = static_cast<int>(floor(log10(maxAbs))) + 1;
    if (minEle < 0) {
        padding++;
    }

    // Print matrix
    for (auto &&row : matrix) {
        for (auto &&ele : row) {
            std::cout << std::left << std::setw(padding) << ele << " ";
        }
        std::cout << "\n";
    }
}

#endif  // MATRIX_H
