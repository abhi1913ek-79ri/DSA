#include<bits/stdc++.h>
using namespace std;
// power(x,n)
// brute
double pow1(double x,int n){
    if(n==0) return 1.0;
    if(x==0) return 0;

    bool isNeg = false;
    long long N = n;

    if(N<0){
        N = -N;
        isNeg = true;
    }

    double ans = 1;
    for(int i=0;i<N;i++){
        ans*=x;
    }

    if(isNeg) return 1/ans;

    return ans;
    // TC = O(n)
    // SC = O(1)
}

// Optimal1 - Using even odd power logic- Binary Exponentiation
// only for positive
double pow2(double x,int n){
    if(n==0) return 1.0;
    if(x==0) return 0;

    double ans = 1;
    while (n>0)
    {
        if(n&1){
            ans*=x;
            n--;
        }else{
            x = x*x;
            n>>=1;
        }
    }

    return ans;
    // TC = O(logN)
    // SC = O(1)  
}

// Optimal-2: also negative
double pow3(double x,int n){
    if(n==0) return 1.0;
    if(x==0) return 0;

    long long N = n;

    bool isNeg = false;
    if(N<0){
        N = -1*N;
        isNeg = true;
    }

    double ans = 1;
    while (N>0)
    {
        if(N&1){
            ans*=x;
            N--;
        }else{
            x = x*x;
            N>>=1;
        }
    }

    if(isNeg) return 1.0/ans;
    return ans;
    // TC = O(logN)
    // SC = O(1)  
}

//  without using isNeg
double pow4(double x,int n){
    if(n==0) return 1.0;

    long long N = n;

    if(N < 0){
        x = 1 / x;   // 🔥 important trick
        N = -N;
    }

    double ans = 1;
    while (N > 0)
    {
        if(N & 1){
            ans *= x;
            N--;
        } else {
            x *= x;
            N >>= 1;
        }
    }

    return ans;
    // TC = O(logN)
    // SC = O(1)
}


// Recursive Version
double helper(double x, long long N){
    if(N == 0) return 1.0;

    if((N & 1) == 0){
        return helper(x * x, N >> 1);
    }

    return x * helper(x, N - 1);
}
double pow5(double x,int n){
    // Base Condition
    if(n==0) return 1.0;

    // negative case handle
    long long N = n;
    if(N<0){
        x = 1/x;
        N = -N;
    }

    return helper(x,N);
    // TC = O(logn)
    // SC = O(n) -- stack space
}


int main(){
    double x = 0;
    int n = 1;
    cout << "x= " << x <<endl;
    cout << "n= " << n <<endl;
    cout << "pow(x,n) : " << pow5(x,n) << endl;
    return 0;
}