#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
// Power(x,n)
int powXN_brute(int x,int n){
    if(x==0 || x == 1) return x; 
    if(n==0) return 1;

    //induction
    return x*powXN_brute(x,n-1);
    // TC = O(n)
    // SC = O(n)
}

// Binary expoentiation
double powXN(double x,long long n){
    // base condition
    if( n == 0) return 1;

    // induction
    if(n%2 == 0){
        return powXN(x*x,n/2);
    }
    return x*powXN(x,n-1);
    // TC = O(logn)
    // SC = O(logn)
}

// Leetcode version
// works for negatives n as well 
// return double 
double powXN_LC(double x,int n){
    if(n < 0) return powXN(1/x,-n);
    return powXN(x,n);
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        double  x;
        cin >> x >> n;
        
        cout << fixed << setprecision(5) << powXN_LC(x,n) << endl;
    }
    
    return 0;
}