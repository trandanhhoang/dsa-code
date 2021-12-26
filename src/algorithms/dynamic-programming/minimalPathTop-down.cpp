#include <iostream>
#include <vector>
using namespace std;

int helper(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) {
    if (row == 1 && col == 1) {
        return grid[0][0];
    }
    if (row == 0 || col == 0) {
        return INT16_MAX;
    }
    if (visited[row][col] >= 0) {
        return visited[row][col];
    }
    visited[row][col] = min<int>(helper(row - 1, col, grid, visited), helper(row, col - 1, grid, visited)) + grid[row - 1][col - 1];
    return visited[row][col];
}

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> visited(201, vector<int>(201, -1));
    int row = grid.size();
    int col = grid[0].size();
    return helper(row, col, grid, visited);
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid);
    //expect = 7
    return 0;
}
