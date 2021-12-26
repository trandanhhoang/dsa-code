#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

int base = 31;
int prime = 1e9 + 7;

int calHashValue(string pat, int lenPat) {
    int sumPat = 0;

    for (int i = 0; i < lenPat - 1; i++) {
        sumPat = ((sumPat + pat[i]) * base);
    }
    sumPat += pat[lenPat - 1];
    return sumPat;
}

void RabinKarp(string doc, string pat) {
    int lenDoc = doc.length();
    int lenPat = pat.length();
    int firstSub = pow(31, lenPat - 1);
    int sumPat = calHashValue(pat, lenPat);
    int sumDoc = calHashValue(doc, lenPat);

    for (int i = 0; i < lenDoc; i++) {
        if (sumPat == sumDoc) {
            for (int j = 0; j < lenPat; j++) {
                if (pat[j] != doc[i + j])
                    break;
                if (j == lenPat - 1)
                    cout << pat << " in " << doc << " at index " << i << endl;
            }
        } else {
            sumDoc = (sumDoc - doc[i] * firstSub) * base + doc[i + lenPat];
        }
    }
}

void Solve(vector<string> docs, string pat) {
    for (auto doc : docs) {
        RabinKarp(doc, pat);
    }
}

int main() {
    string doc1 = "abccbanksgovermentbank";
    string doc2 = "banbanbank government bank";
    string doc3 = "Loc Quoc Huy";
    vector<string> docs;
    docs.push_back(doc1);
    docs.push_back(doc2);
    docs.push_back(doc3);
    string pat = "bank";
    Solve(docs, pat);
    return 0;
}
