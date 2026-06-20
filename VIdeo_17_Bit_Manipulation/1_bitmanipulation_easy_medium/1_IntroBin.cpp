#include<bits/stdc++.h>
using namespace std;
// INTRO TO BIN 

// POS - INT - as normal form stored
// NEG - INT - stored in 2's Complement
// INT_MAX - 2^31 - 1 (32 bits)
// INT_MIN - (-ve)2^31


// 32 bit

// ✅ Algorithm 1: Decimal → Binary (32-bit Signed)
// Input: Integer n
// Output: 32-bit Binary String
// 🔹 Steps:
// If n == 0
// Return string of 32 zeros.
// Create a boolean variable isNegative = false.
// If n < 0
// Set isNegative = true
// Convert n = -n
// Initialize empty string res.
// While n > 0
// Append (n % 2) to res
// Update n = n / 2
// While length of res < 32
// Append '0'
// Reverse the string res.
// If isNegative == false
// Return res
// If isNegative == true
// Take 1’s complement of res
// Add 1 to the result (2’s complement)
// Return final string

// ✅ Algorithm 2: Binary → Decimal (32-bit Signed)
// Input: 32-bit Binary String s
// Output: Signed Integer
// 🔹 Steps:

// If first bit s[0] == '0'

// Number is positive

// Convert binary to decimal normally

// Return result

// Else (if s[0] == '1')

// Number is negative

// Take 1’s complement of s

// Add 1 (2’s complement)

// Convert result to decimal

// Return negative of that value

// decToBin -- work only for positive
string decToBin(int n){
    if(n == 0) return string(32, '0'); // direct string construction
    string res = "";
    while (n>0)
    {
        res += (n&1) + '0';
        n >>= 1;
    }
    
    while (res.length() < 32)
    {
        res+='0';
    }
    
    reverse(res.begin(),res.end());
    
    return res;
    // TC = log(n) = log(1)
    // SC = log(1)
}


// works only for positive numbers 
int binToDec(string s){
    int ans  = 0;
    int  p = 1;
    for (int i = s.length()-1; i >= 0; i--){
        ans += (s[i]-'0' )*p;
        p <<= 1;
    }
    
    return ans;
}

// works for both negative and positive ----------------------------------

string onesComplement(string s){
    for(int i = 0 ; i<32 ;i++){
        s[i] = s[i]=='0' ? '1':'0';
    }
    return s;
}

string twosComplement(string s){
    s = onesComplement(s);
    int carry = 1;
    for(int i= 31 ; i>=0;i--){
        int sum =( s[i]-'0')+ carry;
        s[i]= (sum%2) + '0';
        carry = sum/2;
    }
    return s;
}


// dec to Bin
string decToBin2(int n){
    if(n == 0) return string(32, '0');

    bool isNegative = false;
    if(n < 0){
        isNegative = true;
        n = -n;
    }

    string res = "";

    // Step 1: normal binary
    while(n > 0){
        res += (n % 2) + '0';
        n /= 2;
    }

    // Step 2: pad to 32 bits
    while(res.length() < 32){
        res += '0';
    }

    reverse(res.begin(), res.end());

    if(!isNegative) return res;

    res = twosComplement(res);

    return res;
}

int binToDec2(string s){ // 2's complement me given hoga for neg
    if(s[0]=='0') return binToDec(s);
    s = twosComplement(s);
    return  -binToDec(s);
}

// Cpp - direct methods
string decToBin3(int n){
    return bitset<32>(n).to_string();
}

int binToDec3(string s){
    return (int)bitset<32>(s).to_ulong();
}




int main(){
    int n = -32;
    string bin = decToBin3(n);
    int dec = binToDec3(bin);
    cout << "Input  : " << n << endl;
    cout << "Bin : " << bin << endl;
    cout << "Dec :" << dec << endl;
    return 0;
}