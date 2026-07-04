#include<bits/stdc++.h>
using namespace std;
// Sum of 1 to N
// IBH 

// Hypothesis 
// sum(n) = 1+2+3+..+n
// sumN(n-1) = 1+2+3+..+n-1

// Induction
// sum(n) = sum(n-1)+n

// base case:
// n == 1 return 1;

int sumN(int n){
    // base condition
    if(n==0) return 0;

    // recusive call
    return n+sumN(n-1);
}



int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << sumN(n) << '\n';
    }
    return 0;
}