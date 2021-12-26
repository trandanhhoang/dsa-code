#include <iostream>
#include <string>
#include <vector>

using namespace std;
int base = 31;
int prim = 1e9 + 7;
int computeHashCode(string pat) {
    int sum = 0;
    int len = pat.length();
    for (int i = 0; i < len; i++) {
        sum += (sum * base + pat[i]) % prim;
    }
    cout << sum;
    return sum;
}
void RabinKarp(string doc, string pat, int hash) {
    int len = pat.length();
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += (sum * base + pat[i]) % prim;
    }
    cout << sum;
}

void searchingForPattern(vector<string> docs, string text2) {
    int hashValue = computeHashCode(text2);
    for (auto childText : docs) {
        RabinKarp(childText, text2, hashValue);
    }
}

int main() {
    vector<string> docs;
    docs.push_back("abababx government alo");
    docs.push_back("hehe banks hehe");
    string s2 = "ababx";
    searchingForPattern(docs, s2);
    return 0;
    // int a = 3e9;
    // cout << ;
    // return 0;
}

// ababx && abababx
// 00120
