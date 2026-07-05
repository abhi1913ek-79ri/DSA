#include<bits/stdc++.h>
using namespace std;
// Fibonacci number

// Hypothesis
// fib(n-1) = correctly return n-1th fib
// fib(n-2) = correctly return n-2th fib

// induction 
// fib(n) = fib(n-1) + fib(n-2)

// Base condition
// if(n == 0 || n == 1) return n


int fib(int n){
    // base condition
    if(n == 0 || n == 1) return n;

    // recursive call
    return fib(n-1) + fib(n-2);
}

// TC = O(2^n)
// SC = O(n)

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << fib(n) << endl;
    }
    
    return 0;
}