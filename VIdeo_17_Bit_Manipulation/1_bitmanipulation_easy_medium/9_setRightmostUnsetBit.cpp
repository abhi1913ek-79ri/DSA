#include<bits/stdc++.h>
using namespace std;

// Set the rightmost bit
// Problem Statement: Given a positive integer n, set the rightmost unset (0) bit of its binary representation to 1 and return the resulting integer.
// If all bits are already set, return the number as it is.
// Input:
//  n = 10 (binary: 1010)  
// Output:
//  11 (binary: 1011)  
// Explanation:
//   The rightmost unset bit is the least significant bit (LSB). Setting it to 1 gives 1011 = 11.

// Example 2:
// Input:
//  n = 7 (binary: 111)  
// Output:
//  7 (binary: 111) 

//  Bit wise manipulation 

// Observe something 
// n = 45 -- 101101
// n = 46 -- 101110
// n = 36 -- 100100
// n = 37 -- 100101
// from above obeservation  we find that after increment of 1 in dec bin representaion me 
// rightmost 0's place become 1 and all left bits reamains as it is 

int setRightMostUnsetbit(int n){
    if( n+1 >0 && ((n+1)&(n))==0) return n;
    return n | (n+1);
}




int main(){
    int n = 7;
    cout << "Bin  n = " << bitset<32>(n).to_string() << endl;
    cout << "After setting last unset bit : " <<  bitset<32>(setRightMostUnsetbit(n)).to_string()<< endl;
    return 0;
}