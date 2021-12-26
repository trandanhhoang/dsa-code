#include <iostream>
#include <vector>
using namespace std;

int helper(int m, int n, vector<vector<int>> &uniPath) {
    if (m == 0 || n == 0) {
        return 0;
    }
    if (m == 1 || n == 1) {
        return 1;
    }
    if (uniPath[m][n] > 0)
        return uniPath[m][n];
    uniPath[m][n] = helper(m - 1, n, uniPath) + helper(m, n - 1, uniPath);
    return uniPath[m][n];
}

int uniquePaths(int m, int n) {
    vector<vector<int>> uniPath(101, vector<int>(101, 0));
    return helper(m, n, uniPath);
}

int main() {
    cout << uniquePaths(10, 10);
    //expect 10,10 = 48620
    //3,2 = 3
    return 0;
}
