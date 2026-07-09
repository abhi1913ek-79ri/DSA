#include<bits/stdc++.h>
using namespace std;
// count good numbers

// Brute Force
// hypothesis 
// CG(n-1) corectly gives good numbers of length n-1

// induction
// CG(n ) = CG(n-1)*choices 
// choices variate at even and odd position

// base condition
// if(n==1) return 5

int countGoodNumbers_brute(long long n){
    int MOD = 1e9+7;
    // base condition
    if(n==1) return 5;

    // induction
    if(n&1){
        return (1LL * 5 * countGoodNumbers_brute(n-1)) % MOD;
    }
    return (1LL*4*countGoodNumbers_brute(n-1))%MOD;
}

// TC(n) = TC(n-1) + O(1)


const int MOD = 1e9+7;

// pow mod
int powMOD(long long base,long long expo){
    if(base == 0) return 0;
    if(expo == 0) return 1;

    if(expo%2 == 0) return powMOD((1LL*base*base)%MOD,expo/2)%MOD;

    return (base*powMOD(base,expo-1))%MOD;
}

// Binary expoentiation
// main kam hain isme power function banana modulo wlaa bus
// we have to calculate ans = pow(5,evenplaces)*pow(4,oddPlaces)
int countGoodNumbers(long long n){
    long long even = (n+1)/2;
    long long odd = n/2;
    return (1LL*powMOD(5,even)*powMOD(4,odd))%MOD;
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << countGoodNumbers(n) << endl;
    }
    
    return 0;
}


// NOTE : 
// Yhan pe maain kam tha khud ka powermodulo functionn banana
// and mod ka sahi se use karna 