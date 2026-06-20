#include<bits/stdc++.h>
using namespace std;
const long long MOD  = 1000000007;

// count good numbers - maths problem simly of combination 
long long powerHelper(long long x , long long n,long long ans){
    if(n == 0) return  ans;
    
    x%=MOD;

    if(n%2==1){
        ans  = (ans*x) % MOD; 
        n -= 1;
    }else{
        x  = (x*x)%MOD;
        n /=2;
    }

    return powerHelper(x,n,ans);
}

long long power(long long x, long long n){
    return powerHelper(x%MOD,n,1);
}
int countGoodNumbers(long long n) {
    long long even = 0;
    long long odd =  1;
    // if(n%2 == 0){
    //     even = n/2.0;
    //     odd = n/2.0;
    // }else{
    //     even = n/2.0 + 1.0;
    //     odd = n/2.0;
    // }


    even = (n+1)/2;
    odd = n/2;

    long long ans  =  (power(5,even)*power(4,odd)) % 1000000007;


    return ans;
}

int main(){
    int n = 5;
    cout << "Num of good string : " << countGoodNumbers(n);
    return 0;
}