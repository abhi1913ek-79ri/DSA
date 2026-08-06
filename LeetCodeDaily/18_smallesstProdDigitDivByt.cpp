#include <bits/stdc++.h>
using namespace std;
// 3345. Smallest Divisible Digit Product I

// brute force
int smallestNumber(int n, int t)
{
    while (n <= 100)
    {
        int m = n;
        int prod = 1;
        while (m)
        {
            prod *= m % 10;
            m /= 10;
        }

        if (prod % t == 0)
            return n;
        n++;
    }
    return -1;
    // TC = O(n*10)
}

int main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;

    cout << smallestNumber(n,t);
    return 0;
}