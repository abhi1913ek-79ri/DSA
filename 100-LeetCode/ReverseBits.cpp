#include<bits/stdc++.h>
using namespace std;
// Reverse Bits
// Thinking Issue  - Number 32 bits hona chahiye ye bhi dhyan me rakh 


string decToBinInReverse(int n){
    string ans = "";
    while(n>0){
        ans += n%2 + '0'; // binary conversion
        n /= 2;
    }
    int lengthOfReverse = ans.length();
    for(int i = 1 ; i<= 32 - lengthOfReverse;i++){
        ans += '0';
    }
    return ans;
}

unsigned int binToDec(string s){
    unsigned int ans  = 0;
    unsigned int r = 1;
    for(int i = s.length()-1;i>=0 ; i--){
        ans +=  (s[i]-'0')*r;
        r*=2;
    }
    return ans;
}




int reverseBitsBrute(int n){
    string s = decToBinInReverse(n);
    return binToDec(s);
    // TC = O(1)
    // SC = O(1)
}

void printString(string s){
    for(auto ch : s){
        cout << ch ;
    }
    cout << endl;
}

// Reverse Bits conclusion:
// 32-bit integer ke bits ko reverse karne ke liye hum number ke bits 
// right-to-left read karte hain aur answer me left-to-right build karte hain. 
// Har iteration me last bit (n & 1) se extract karte hain, answer ko ans << 1 se
//  ek position left shift karke space banate hain, phir | operator se bit add 
// kar dete hain (ans = (ans << 1) | (n & 1)), aur n >>= 1 se next bit par move 
// karte hain. Ye process exactly 32 times chalti hai kyunki integer 32-bit ka 
// hota hai. Is approach ki time complexity O(1) aur space complexity O(1) hoti
//  hai, aur ye string-based brute force se zyada optimal aur interview-expected 
// solution hai.

// Bits manipulatoion
// Without Extra Space

int reverseBitsOptimal(int n){
    unsigned int ans = 0;

    for(int i =0 ;i<32 ;i++)
    {
        int last_bit = n&1;
        ans <<= 1; // space banao
        ans |= last_bit; // last bit add
        n >>=1;
    }
    return ans;  
}


int main(){
    int n = 43261596;
    string s = decToBinInReverse(n);
    cout << "n ="<<n<<endl;
    cout << "Bin =";
    printString(s);
    cout << "Afetr reversal n=" <<reverseBitsOptimal(n);
    return 0;
}