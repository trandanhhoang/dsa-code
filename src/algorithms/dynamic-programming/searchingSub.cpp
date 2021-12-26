#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> computeLPS(string pat) {
    int M = pat.length();
    int len = 0;
    int i = 1;
    vector<int> lps(M, 0);
    while (i < M) {  //ababx
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMPSearch(string doc, string pat, vector<int> lps) {
    int N = doc.length();
    int M = pat.length();
    int iDoc = 0;
    int iPat = 0;
    while (iDoc < N) {
        if (doc[iDoc] == pat[iPat]) {
            iDoc++;
            iPat++;
            continue;
        }
        if (iPat == M) {
            cout << "\"" << pat << "\" in \"" << doc << "\" at index " << iDoc - iPat << endl;
            break;
        } else if (iDoc < N && pat[iPat] != doc[iDoc]) {
            if (iPat != 0)
                iPat = lps[iPat - 1];
            else
                iDoc = iDoc + 1;
        }
    }
}

void searchingForPattern(vector<string> docs, string text2) {
    vector<int> lps = computeLPS(text2);
    for (auto childText : docs) {
        KMPSearch(childText, text2, lps);
    }
}

int main() {
    vector<string> docs;
    docs.push_back("abababx government alo");
    docs.push_back("hehe banks hehe");
    string s2 = "ababx";
    searchingForPattern(docs, s2);
    return 0;
}

// ababx && abababx
// 00120
