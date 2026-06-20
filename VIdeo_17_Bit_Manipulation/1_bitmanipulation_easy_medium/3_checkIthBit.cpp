#include<bits/stdc++.h>
using namespace std;
// check ith bit is set or not 

// Brute force - ith position
bool isSetBit(int n, int k){
    string bin = bitset<32>(n).to_string();
    for(int i = bin.length()-1;i>=0;i--){
        if(i == k) return bin[i]=='1';
    }
}

// Bitwise operatror ka - optimal ( left Shift)
bool isSetBit2(int n,int k){
    return n & (1<<k);
}


// Bitwise operatror ka - optimal ( right Shift) // negative numbers me dikkat ho skta hain
bool isSetBit3(int n,int k){
    return (n>>k)&1 ;
}


int main(){
    int n = 13; // 1101
    int k = 2;
    cout << "n = " << n << " bin = " << bitset<32>(n).to_string() << endl;
    cout << k<<"th bit is set : " << ( isSetBit3(n,k) ? "true" : "false") << endl;  
    return 0;
}