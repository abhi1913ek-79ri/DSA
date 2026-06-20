#include <bits/stdc++.h>
using namespace std;
// Problem Statement: Write a function to find
// the longest common prefix string amongst an array
// of strings. If there is no common prefix, return an empty string "".


void printString(string s){
    for(auto c:s) cout<<c;
}

void printArray(vector<string>& arr){
    cout<<"[";
    for(auto str : arr){
        printString(str);
        cout<<",";
    }
    cout<<"]\n";
}

//  checkling that pair i,j in s and t that are equal or not 
bool isIsomorphicBrute(string s, string t){
    if(s.length()!=t.length()) return false;

    for(int i=0;i<s.length();i++){
        for(int j = i+1; j<s.length();j++){
            if((s[i]==s[j] && t[i]!=t[j] )|| (s[i]!=s[j]&& t[i]==t[j] )) return false;
        }
    }
    return true;
    // TC = O(n²)
    // SC = O(1)
}

bool isIsomorphicOptimal(string s, string t){
    if(s.length()!=t.length()) return false;
    if(s==t)  return true;

    unordered_map<char,char> mapST;
    unordered_map<char,char> mapTS;



    //checking mapp ww are checking here bijection --  one to one and onto 
    for(int i = 0;i<s.size();i++){
        char c1 = s[i];
        char c2 = t[i];

        // forward mapping s to t
        if(mapST.count(c1)){
            if(mapST[c1]!=c2) return false;
        }else{
            mapST[c1] = c2;
        }

        // reverse mapping t to s
        if(mapTS.count(c2)){
            if(mapTS[c2]!=c1) return false;
        }else{
            mapTS[c2] = c1;
        }
    }

    return true;
    // TC = O(n)
    // SC = O(1) or constant as there are only 256 char
}


int main(){
    string s = "egg";
    string t = "add";

    bool isIso = isIsomorphicBrute(s,t);

    cout<<"s = ";printString(s);cout<<"\n";
    cout<<"t = ";printString(t);cout<<"\n";

    if(isIso) printString("s & t are isomorphic.");
    else printString("s & t are not isomorphic.");

    return 0;
}