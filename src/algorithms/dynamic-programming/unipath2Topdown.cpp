#include <iostream>
#include <vector>
using namespace std;

int helper(int m, int n, vector<vector<int>>& uniPath, vector<vector<int>>& obstacleGrid, int row, int col) {
    if (m == 0 || n == 0) {
        return 0;
    }
    if (obstacleGrid[row - m][col - n] == 1) return 0;

    if (m == 1 && n == 1) {
        return 1;
    }
    if (uniPath[m][n] > -1)
        return uniPath[m][n];
    uniPath[m][n] = helper(m - 1, n, uniPath, obstacleGrid, row, col) + helper(m, n - 1, uniPath, obstacleGrid, row, col);
    return uniPath[m][n];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>> uniPath(101, vector<int>(101, -1));
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    return helper(m, n, uniPath, obstacleGrid, m, n);
}

int main() {
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    cout << uniquePathsWithObstacles(obstacleGrid);
    //expect = 2
    return 0;
}
