#include <iostream>
#include <vector>
using namespace std;

//0,1, 1, 2, 3, 5, 8
#define MAX 1000000
vector<int> arr2(1000000, 0);

long long fiboStandard(int n) {
    if (n < 2) {
        return n;
    } else if (arr2[n] > 0) {
        return arr2[n];
    } else {
        arr2[n] = fiboStandard(n - 1) + fiboStandard(n - 2);
        return arr2[n];
    }
}

int fibo(int n) {
    //filling array, bottum up
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n - 1];
}

int main() {
    cout << fiboStandard(100000);
    return 0;
}
