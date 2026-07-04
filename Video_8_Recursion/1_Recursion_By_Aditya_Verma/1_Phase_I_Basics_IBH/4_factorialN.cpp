#include<bits/stdc++.h>
using namespace std;
// factorial N
// IBH 

// Hypothesis 
// fact(n) = 1*2*3*...*n
// fact(n-1) = 1*2*3*...*n-1

// Induction
// fact(n) = fact(n-1)*n

// base case:
// n == 0 || n == 1 return 1;

int fact(int n){
    // base condition
    if(n==0 || n==1) return 1;

    // recusive call
    return n*fact(n-1);
}



int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << fact(n) << '\n';
    }
    return 0;
}