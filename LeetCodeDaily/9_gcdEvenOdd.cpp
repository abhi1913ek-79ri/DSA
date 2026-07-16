#include <bits/stdc++.h>
using namespace std;


// Brute : logn
// Euclid algorithm
int GCD(int a, int b) {
    while (b) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int gcdOfOddEvenSums(int n) {
    int sumOdd = n * n;
    int sumEven = n * n + n;

    return GCD(sumEven, sumOdd);
}

//  Optimal : observation of mathematical formula
// GCD(n*n , n*(n+1)) = n;
int gcdOfOddEvenSums_optimised(int n) {
    return n;
    // TC = O(1)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << gcdOfOddEvenSums_optimised(n);

    return 0;
}