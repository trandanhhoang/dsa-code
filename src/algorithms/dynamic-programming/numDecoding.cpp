#include <iostream>
#include <string>
#include <vector>
using namespace std;
int calNum(string s, int i, vector<int> &dp) {
    int len = s.length();
    if (i == len) {
        return 1;
    }
    if (dp[i] >= 0) {
        return dp[i];
    }
    dp[i] = 0;
    if (s[i] != '0') {
        dp[i] += calNum(s, i + 1, dp);
    }

    if (i != len - 1) {
        int twoChar = (s[i] - '0') * 10 + s[i + 1] - '0';
        if (twoChar <= 26 && twoChar >= 10) {
            dp[i] += calNum(s, i + 2, dp);
        }
    }
    return dp[i];
}

int numDecodings(string s) {
    int len = s.length();

    vector<int> dp(len, -1);
    return calNum(s, 0, dp);
}

int main() {
    string str = "11111";
    cout << numDecodings(str);
    //expect = 7
    return 0;
}
