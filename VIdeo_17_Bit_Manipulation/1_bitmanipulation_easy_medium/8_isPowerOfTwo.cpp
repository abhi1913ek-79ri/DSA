#include<bits/stdc++.h>
using namespace std;
// isPowerOfTwo

bool isPowerOf2(int n){
    string bin = bitset<32>(n).to_string();
    int cnt = 0;
    for(int i = 31 ; i>=0 ;i--){
        if(bin[i]=='1') cnt++;
    }
    return cnt==1;
    // TC = O(32)
    // SC = O(32)
}


// using bit-manipulation -- brute == count set bit 
bool isPowerOf2B(int n){
    int cnt  = 0;
    while (n!=0)
    {
        n = n&(n-1); // removes last set bit
        cnt++;
    }
    return cnt==1;
    // TC = O(32)
    // SC = O(1)
}

// bit-manipulation optimal
bool isPowerOf2C(int n){
    return n>0 && (n&(n-1))==0;
    // TC = O(1);
    // SC = O(1);
}

int main(){
    int n = 0;
    cout <<"N = " << n << " is power of 2 : " << (isPowerOf2C(n) ? "True" : "False") << endl;
    return 0;
}