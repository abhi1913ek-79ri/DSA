#include<bits/stdc++.h>
using namespace std;
// Basics of Hashing 
// Hashing : Pre-storing Key-may be same character/number or Hash-value returned By hash- function & fetch the value 
// associated with that key/hash-value

// Character - Hashing
// 3. 256-charaters Hashing using ASCII-Seedha Seedha -Store
int main(){
    string name="abhishekkumargiri";
    vector<int> hashh(256,0);
    // pre-computation :  hash-value=ch ;ASCII-Seedha Seedha -Store
    for(char ch:name) hashh[ch]++;
    // fetch :  hash-value=ch  : for given their is unique hash-value :ASCII-Seedha Seedha -Store
    for(auto ch : name) cout << ch <<"->"<<hashh[ch]<<endl;
    return 0;
}