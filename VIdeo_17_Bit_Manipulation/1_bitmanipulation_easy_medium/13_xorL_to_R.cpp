#include<bits/stdc++.h>
using namespace std;
// XOR L to R 

// Brute Force approach
// loop from L to R
int XORLR(int l,int r){
    cout <<0 <<"\n";
    int ans = 0;
    for(int i = l ; i<=r ;i++){
        ans^=i;
        cout<< ans << "\n";
    }
    return ans;
    // TC = O(n)
    // SC = O(1)
    // TLE when n>10e9
}

// observation solution --- after 
// obeservation  i found that 
// 4n to 4(n+1) - 1 tak ka XOR =0 always
int justGreaterNumDivBy4(int n){ // optimised by me
    return n + 4-(n%4);
}
int justLesserNumDivBy4(int n){
    return n - (n%4);
}
int XORLR2(int l,int r){
    int lowerBoundZeroSum = justGreaterNumDivBy4(l);
    int upperBoundZerosum = justLesserNumDivBy4(r);

    int ans = 0;

    for(int i=l;i<lowerBoundZeroSum;i++){
        ans ^= i;
    }

    for(int i=upperBoundZerosum;i<=r;i++){
        ans^=i;
    }

    return ans;
    // TC = O(8)
}



// strivers solution 1^2^3^...^n = 
// n%4 == 1 => 1
// n%4 == 2 => n+1
// n%4 == 3 => 0
// n%4 == 0 => n
int xor1toN(int n){
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
    return n;
}

int XORLR3(int l,int r){ // strivers solution
    int ans = xor1toN(r)^xor1toN(l-1); // becoz X^A^X^A = 0 and 0^X^A =X^A
    return  ans;
    // O(1)
}


int main(){
    int l = 3;
    int r = 5;
    cout << "XOR of num is range ("<<l<<","<<r<<") : "<<XORLR3(l,r)<<endl;
    cout <<( 0^1^2^3);
    return 0;
}