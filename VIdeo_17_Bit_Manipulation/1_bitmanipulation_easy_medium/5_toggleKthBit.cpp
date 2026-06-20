#include<bits/stdc++.h>
using namespace std;
// toggle ith bit --

// XOR 
// 1^1 = 0
// 1^0 = 1
// same = 0
// diff = 1

// BruteForce - convert to binary then traverse to kth 

int toggleKthBit1(int n,int k){
    string bin = bitset<32>(n).to_string();
    for(int i=0;i<32;i++){
        if(i==k){
            bin[32-i-1] =( (bin[32-i-1]=='0' )? '1' : '0');
        }
    }
    return (int)bitset<32>(bin).to_ulong();
    // TC = O(32)
    // SC = O(32)
}

// bitwise operator - brute 
// if(isSet) clear
// if(not(isSet)) set

bool isSetBit(int n, int k){
    return n & (1 << k);
}

int setKthBit(int n, int k){
    return n | ( 1 << k);
}

int clearKthBit(int n, int k){
    return n & (~( 1 << k));
}

int toggleKthBit2(int n, int k){
    if(isSetBit(n,k)) return clearKthBit(n,k);
    return setKthBit(n,k);
}

// bitwise XOR approach

int toggleKthBit3(int n, int k){
    return n ^ ( 1 << k);
}



int main(){
    int n = 13;
    int k = 0;
    cout << "n = " << bitset<32>(n).to_string()<< endl;
    cout << "After toggle " <<1<< "th bit \nn = " << bitset<32>(toggleKthBit3(n,1)).to_string()<< endl;
    cout << "After toggle " <<0<< "th bit \nn = " << bitset<32>(toggleKthBit3(n,0)).to_string()<< endl;
    cout << "After toggle " <<2<< "th bit \nn = " << bitset<32>(toggleKthBit3(n,2)).to_string()<< endl;
    cout << "After toggle " <<3<< "th bit \nn = " << bitset<32>(toggleKthBit3(n,3)).to_string()<< endl; 
    cout << "After toggle " <<5<< "th bit \nn = " << bitset<32>(toggleKthBit3(n,5)).to_string()<< endl; 

    return 0;
}

