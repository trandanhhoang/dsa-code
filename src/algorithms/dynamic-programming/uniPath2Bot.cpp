#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1)
        return 0;

    vector<vector<int>> uniPath(101, vector<int>(101, 0));
    uniPath[1][1] = 1;

    for (int col = 1; col <= m; col++) {
        for (int row = 1; row <= n; row++) {
            // if (row == 1 && col == 1) continue;
            if (obstacleGrid[col - 1][row - 1] == 1) {
                uniPath[col][row] = 0;
                continue;
            }
            if (row == 1 && col == 1) continue;
            uniPath[col][row] = uniPath[col][row - 1] + uniPath[col - 1][row];
        }
    }

    return uniPath[m][n];
}

int main() {
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    cout << uniquePathsWithObstacles(obstacleGrid);
    //expect = 2
    return 0;
}
