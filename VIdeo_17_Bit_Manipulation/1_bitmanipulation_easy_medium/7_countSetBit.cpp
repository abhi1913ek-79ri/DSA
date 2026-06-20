#include<bits/stdc++.h>
using namespace std;
// cnt set bit 

// brute
int countSetBit(int n){
    int cnt = 0;
    string bin = bitset<32>(n).to_string();
    for(auto ch : bin){
        if( ch == '1') cnt++;
    }
    return cnt;
    // TC = O(32)
    // SC = O(32)
}


// using bitwise operator -- optimal 
// Brian Kernighan Algorithm
int countSetBit2(int n){ 
    int res = 0;
    while(n>0){
        n = n&(n-1);
        res++;
    }
    return res;
    // TC = O(no. of set bit)
    // SC = O(32)
}

// built in __builtin_popcount(n); function
int countSetBit3(int n){
    return __builtin_popcount(n);
}


 
int main(){
    int n = 13;
    cout << "No. of set Bits in " << bitset<32>(n).to_string() << " :  " << countSetBit3(n) << endl;
    return 0;
}