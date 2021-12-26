#include <iostream>
#include <vector>

using namespace std;

int longestSubSequenceNoRepeat(string s) {
    int maxStart = 0, maxLen = 0;
    int start = 0;
    vector<int> indexes(128, -1);
    //abcdajk.
    for (int i = 0, j = 0; j < s.length(); j++) {
        //find i
        i = max<int>(i, indexes[s[j]] + 1);
        //find len
        maxLen = max<int>(maxLen, j - i + 1);
        //cap nhat s[j]
        indexes[s[j]] = j;
    }
    return maxLen;
}

int main() {
    cout << longestSubSequenceNoRepeat("abcabc");
    return 0;
}
