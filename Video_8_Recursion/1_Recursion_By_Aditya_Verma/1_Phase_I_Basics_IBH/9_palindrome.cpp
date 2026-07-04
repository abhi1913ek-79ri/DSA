#include<bits/stdc++.h>
using namespace std;
// pallindrome

// using two pointers and helper function
bool isPalindrome(string& s,int l,int r){
    // base condition
    if(l>=r) return true;

    // recursiv call
    return (s[l] == s[r]) && isPalindrome(s,++l,--r);
}

// TC = O(n/2)
// SC = O(n/2) - recurve call stack

int main(){
    int t;
    cin >> t;
    cin.ignore(); //-- ignore next line after cin
    while (t--)
    {
        string s;
        getline(cin,s);
        cout << isPalindrome(s,0,s.length()-1) << endl;
    }
    
    return 0;
}