#include<bits/stdc++.h>
#include <iomanip> // for precision decimal places
using namespace std;
// I am assuming n= positive integer and 0
// and x is integer
// pow(x,n)

// hypothesis
// pow(x,n-1) = x*x*x...n-1 times 

// induction
// pow(x,n) = x*pow(x,n-1);

// base condition
// n == 0 return 1
// x == 0 return 0

double powXN(double x,int n){
    // base condition
    if(x==0) return 0;
    if(n == 0) return 1;

    // recursive call
    return x*powXN(x,n-1);
}

// TC = O(n)
// SC = O(n) - recursive call stack



int main(){
    int t;
    cin >> t;
    while(t--){
        double x;
        int n;
        cin >> x >> n;
        cout << fixed << setprecision(5) << powXN(x, n) << '\n'; // set precision upto 5 decimal places
    }
    return 0;
}