#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> uniPath(101, vector<int>(101, 0));
    for (int i = 1; i <= 100; i++) {
        uniPath[i][1] = 1;
        uniPath[1][i] = 1;
    }
    for (int row = 2; row <= m; row++) {
        for (int col = 2; col <= n; col++) {
            uniPath[row][col] = uniPath[row][col - 1] + uniPath[row - 1][col];
        }
    }

    return uniPath[m][n];
}

int main() {
    cout << uniquePaths(10, 10);
    //expect 10,10 = 48620
    //3,2 = 3
    return 0;
}
