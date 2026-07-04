#include<bits/stdc++.h>
using namespace std;
// Reverse a string

// hyphthesis
// assumes 
// reverse(s.substr(1)) correctly reverse s.subtr(1)

// induction
// reverse(s) = reverse(s.substr(1)) + s[0]

// base condition
// s == "" return "";

string reverseStr(string s){
    // base condition
    if(s == "") return s;

    // recrsive call 
    return reverseStr(s.substr(1)) + s[0];
}

// TC = O(n^2)
// SC = O(n) recursive call stack

int main(){
    int t;
    cin >> t;
    cin.ignore(); // ignore next line 
    while (t--)
    {
        string s;
        getline(cin,s);
        cout << reverseStr(s) << "\n";
    }
    
    return 0;
}