#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> arr(10000, 1);

//[10,9,2,5,3,7,101,18]
int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.length() - 1;
    int len2 = text2.length() - 1;
    int maxResult = 0;
    if (len1 == -1 || len2 == -1) {
        return 0;
    }
    while (len1 >= 0) {
        len2 = text2.length();
        while (len2 >= 0) {
            if (text1[len1] == text2[len2]) {
                maxResult = max<int>(maxResult, longestCommonSubsequence(text1.substr(0, len1), text2.substr(0, len2)) + 1);
            }
            len2--;
        }
        len1--;
    }
    return maxResult;
}

int main() {
    string s1 = "aghtacdb";
    string s2 = "gxtxaybu";
    cout << longestCommonSubsequence(s1, s2);
}
