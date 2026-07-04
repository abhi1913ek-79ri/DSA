#include<bits/stdc++.h>
using namespace std;
// print 1 to N using recusion
// IBH - method 

// Hypothesis print(N) = 1,2,3,4,...,N
// --- then print(N-1) = 1,2,3,4,...,N-1
// Induction -- print(N) = print(N-1),N
// Base Condition : smallest valid input , largest invalid input 
// here base condition : N == 1

void print1ToN(int n){
    // BC
    if(n==1){
        cout << n  << " ";
        return;
    }

    // jatey samay ka kaam 
    // cout << n << " ";

    // recusrive call -- smaller input
    print1ToN(n-1);

    // aatey samay ka kaam 
    cout << n << " ";
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