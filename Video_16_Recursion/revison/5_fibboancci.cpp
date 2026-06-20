#include<bits/stdc++.h>
using namespace std;

// find fib(5th) by loop method
int fib(int n){
    if(n<=1) return n;
    int prev1 = 1;
    int prev2 = 0;
    int curr = 0;
    for(int i = 2;i<=n;i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
    // TC = O(n)
    // SC = O(1)
}

// By recusion - MUltiple recusion example

int cnt = 0;  // global counter

int fib2(int n) {
    cnt++;
    // increment each time function is called
    if(n <= 1) return n;
    cout << cnt <<" ";
    return fib2(n-1) + fib2(n-2);
    // TC = O(2^n)
    // SC = O(n)
}


int main(){
    int n = 5;
    fib2(5);
    cout << "Recusion calls : " << cnt;
    return 0;
}