#include<bits/stdc++.h>
using namespace std;

// Remove last Set Bit -- brute 
// convert to binary string traverse from end and then clear the last set bit
int removeLastSetBit(int n){
    string bin  = bitset<32>(n).to_string();
    for(int i = bin.length() - 1 ; i >= 0 ;i--){
        if(bin[i] == '1') {
            bin[i]='0';
            break;
        }
    }
    return (int) bitset<32>( bin).to_ulong();
    //TC = O(32)
    // SC = O(32)
}

// Using bitwise operator

// obeservation that n & n-1 
//  n =  1100011000
//  n =  1100010111
//  this works always
int removeLastSetBit2(int n){
    return n & (n-1);
    // TC = O(1)
}



int main(){
    int n = 1;
    cout << "n = " << bitset<32>(n).to_string() << endl;
    cout << "after removal of last set bit n = " << bitset<32>(removeLastSetBit2(n)).to_string()<< endl;
    return 0;
}