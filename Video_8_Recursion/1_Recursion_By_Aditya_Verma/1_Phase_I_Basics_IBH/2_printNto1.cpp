#include<bits/stdc++.h>
using namespace std;
// print N to 1 using recusion
// IBH - method 

// Hypothesis print(N) = N, ... , 4 ,3,2,1
// --- then print(N-1) = N-1, ... , 4 ,3,2,1
// Induction -- print(N) = print(N-1),N
// Base Condition : smallest valid input , largest invalid input 
// here base condition : N == 1

// Hypothesis:
// print(n-1) correctly prints:
// n-1, n-2, ..., 2, 1

// Induction:
// First print n
// Then call print(n-1)

void print1ToN(int n){
    // BC
    if(n==1){
        cout << n  << " ";
        return;
    }

    // jatey samay ka kaam 
    cout << n << " ";

    // recusrive call -- smaller input
    print1ToN(n-1);

    // aatey samay ka kaam 
    // cout << n << " ";
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        print1ToN(n);
        cout << '\n';
    }
    return 0;
}