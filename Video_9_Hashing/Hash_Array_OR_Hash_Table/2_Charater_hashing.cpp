#include<bits/stdc++.h>
using namespace std;
// Basics of Hashing 
// Hashing : Pre-storing Key-may be same character/number or Hash-value returned By hash- function & fetch the value 
// associated with that key/hash-value

// Character - Hashing
// 1. Lower Case : 26-sized hash :: hashValue- char-'a'
// 2. upper- case: 26-sized hash :: hashValue- char-'A'
// 3. 256-charaters Hashing using ASCII
int main(){
    string name="abhishekkumargiri";
    vector<int> hashh(26,0);
    // pre-computation :  hash-value=ch-'a'
    for(char ch:name) hashh[ch-'a']++;
    // fetch :  hash-value=ch-'a'  : for given their is unique hash-value
    for(auto ch : name) cout << ch <<"->"<<hashh[ch-'a']<<endl;
    return 0;
}