#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).
// Examples:
// Example 1:
// Input: x = 2.00000, n = 10
// Output: 1024.00000

// pow(x,n) - loop method
double pow1(double x, int n){
    if(x == 0) return 0;
    if(n == 0) return 1.0;

    double ans  = 1.0;

    if(n < 0){
        while ((-n)> 0)
        {
            ans/=x;
            n++;
        }

        return ans;
    }

    for(int i = 0;i<n;i++){
        ans*=x;
    }
    return ans;
    // TC = O(n) - TLE
    // SC = O(1)
}


// recusionm helper
double powHelper(double x,int n,double ans){
    // stop condition
    if(n == 0) return ans;
    return powHelper(x,n-1,ans*x);
    
}

// pow(x,n) - recursion method
double pow2(double x, int n ){
    double ans = powHelper(x,n,1);
    return ans;
    // TC = O(n) - TLE
    // SC = O(n)
}


// Algorithm -- Binary exponentiation Algorithm 
double pow3(double x,int n){
    if(x == 0) return 0;
    if(n == 0) return 1.0;

    double ans = 1.0;
    // positive number n = +I 
    while(n>0){
        if(n%2==1){
            ans*=x;
            n-=1;
        }else{
            x *= x;
            n/=2;
        }
    }

    while (n<0)
    {
        if(!(n%2==0)){
            ans/=x;
            n++;
        }else{
            x*=x;
            n/=2;
        }
    }
    
    return ans;
    // TC = O(logn)
    // SC = O(1)
}

// Recusion - logn and space O(logn)
double powHelper4(double x,int n,double ans){
    // stoping condition
    if(n == 0) return ans;

    if(n>0){ // positive case

        if(n%2==1){ // odd
            ans *= x;
            n -= 1;
        }else{ // even power - (chnages the parameters x,n ) -> same in both negative as well as positive
            x *= x;
            n /=2;
        }
    }else if(n<0){

        if(!(n%2==0)){ // odd
            ans /= x;
            n += 1;
        }else{ // even power - (chnages the parameters x,n ) -> same in both negative as well as positive
            x *= x;
            n /=2;
        }
    }

    return powHelper4(x,n,ans);
}

double pow4(double x,int n){
    if(x == 0) return 0;
    if(n == 0) return 1.0;
    double ans = 1.0;
    
    ans  = powHelper4(x,n,ans);
    return ans;
    // TC = O(logn)
    // SC = O(logn)
}



int main(){
    double x = 2.0;
    int n = -5;
    cout << "x = "<<x<<" and n = "<<n<<endl;
    cout <<"pow("<<x<<","<<n<<") = " << pow4(x,n)<<endl;
    return 0;
}