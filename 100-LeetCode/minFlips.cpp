#include<bits/stdc++.h>
using namespace std;
// wrong

bool isAlternate(string s){
    bool flag = true;
    int i = 1;
    int n = s.length();
    while (flag && i < n)
    {
        if(s[i]!=s[i-1]){
            i++;
        }else{
            flag = false;
            i++;
        }
    }
    return flag;
    // TC = O(n)
}


int minFlips(string s) {
    int minFlip = 0;
    int n = s.length();
    if(s[0] != s[n-1]){
        s[0]^=1;
        s[n-1]^=1;
    }
    if(isAlternate(s)) return minFlip;

    for(int i = 1; i<n;i++){
        if(s[i] == s[i-1]){
            s[i]^=1;
            minFlip++;
        }
    }

    return minFlip;
    // TC = O(3n)
}

int main(){
    string s = "0111";
    cout << "Min flips : " << minFlips(s)<<endl;
    return 0;
}