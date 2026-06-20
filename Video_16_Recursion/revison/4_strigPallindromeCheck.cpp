#include<bits/stdc++.h>
using namespace std;

// string pallindrome - loop without reversing just checking
bool isPallindrome1(string & s){
    int n = s.length();
    for(int i = 0;i<n/2;i++){
        if(s[i]!=s[n-i-1]) return false;
    }
    return true;
    // TC = O(n/2)
    // SC = O(1)
}

// string pallindrome - loop with reversing 
bool isPallindrome2(string & s){
    int n = s.length();
    string m = s;
    for(int i  = 0;i<n/2;i++){
        swap(m[i],m[n-i-1]);
    }

    return s == m; // comapare
    // TC = O(n/2+n)
    // SC = O(n)
}


// using recusion
bool isPallindrome3(string& s,int i){
    int n = s.length();
    if(i>n/2) return true;
    if(s[i]!=s[n-i-1]) return false;

    return isPallindrome3(s,i+1);
    
    // TC = O(n/2)
    // SC = O(n/2)
}

int main(){
    string s = "NITIN";
    string t = "SIR";

    cout << "s is pallindrome : "<< isPallindrome3(s,0)<<endl;
    cout << "t is pallindrome : "<< isPallindrome3(t,0)<<endl;


    return 0;
}