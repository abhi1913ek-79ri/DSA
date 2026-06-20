#include <bits/stdc++.h>
using namespace std;

void printString(string s){
    for(auto c:s) cout<<c;
    cout<<"\n";
}

string shiftString(string & s){
    char start = s[0];
    for(int i = 0;i<s.length()-1;i++){
        s[i] = s[i+1];
    }
    s[s.length()-1] = start;
    return s;
}

bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) return false;
    int shift = 0;
    while(s != goal && shift<s.length()){
        s=shiftString(s);
        shift++;
    }
    if(s==goal) return true;
    return false;
// Metric	    Complexity
// Time	O(n²) — because you rotate n times, and each rotation costs O(n)
// Space	    O(1) — in-place shifting
}



// using the information that if s can be rotated to goal then goal is substring of s+s 
bool rotateStringOptimal1(string s,string goal){
    if(s.length()!=goal.length()) return false;

    string doubleS = s+s;

    if(doubleS.find(goal)<=0) return false;

    return true;
}

int main(){
    string s = "abcde", goal = "cdeab";
    cout<<"s= ";printString(s);
    cout<<"goal= ";printString(goal);

    bool canBe = rotateString(s,goal);

    cout << "can be  : " << canBe<<endl;
    return 0;
}