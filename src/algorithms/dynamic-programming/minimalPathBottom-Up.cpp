#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> visited(201, vector<int>(201, -1));
    int row = grid.size();
    int col = grid[0].size();

    visited[1][1] = grid[0][0];
    for (int i = 1; i <= row; i++) {
        visited[i][0] = INT16_MAX;
    }
    for (int i = 0; i <= col; i++) {
        visited[0][i] = INT16_MAX;
    }
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if (i == 1 && j == 1) continue;
            visited[i][j] = min<int>(visited[i - 1][j], visited[i][j - 1]) + grid[i - 1][j - 1];
        }
    }

    return visited[row][col];
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid);
    //expect = 7
    return 0;
}
