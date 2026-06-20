#include<bits/stdc++.h>
using namespace std;

// 🚀 TL;DR Summary Ladder
// Version	Name	Time	Space	Notes
// Brute2	Sort (mutating)	O(n log n)	O(1)	Simple, unsafe
// Brute3	Sort (copy)	O(n log n)	O(n)	Safe version
// Better	2 maps	O(n)	O(n)	Redundant double loop
// Better2	1 map	O(n)	O(n)	✅ Clean and optimal general
// Optimal	26-array	O(n)	O(1)	✅ Fastest in practice

void printString(string s){
    for(auto c:s) cout<<c;
    cout<<"\n";
}


// Sorting approach  -- by mutating data
bool isAnargamFunBrute2(string & s , string & t){
    sort(s.begin(),s.end()); // nlogn
    sort(t.begin(),t.end()); // nlogn
    return s == t;
    // Time = O(n log n)
    //Space = O(1) (in-place sort)
}

// Sorting approach  -- without mutating data
bool isAnargamFunBrute3(string & s , string & t){
    string a=s, b=t;
    sort(a.begin(),a.end()); // nlogn
    sort(b.begin(),b.end()); // nlogn
    return a == b;
    // Time = O(n log n)
    //Space = O(2n) 
}


// count the frequency - hash map
bool isAnargamFunBetter(string s,string t){
    unordered_map<char,int> freqS;
    unordered_map<char,int> freqT;


    // O(n)
    for(auto ch :s ){
        freqS[ch]++;
    }
    // O(n)
    for(auto ch :t ){
        freqT[ch]++;
    }
    // O(n)
    for(auto it = freqS.begin();it!=freqS.end();it++){
        if(freqT.find(it->first)!=freqT.end()){
            if(freqT[it->first] != it->second){
                return false;
            }
        }else{
            return false;
        }
    }
    // O(n)
    for(auto it = freqT.begin();it!=freqT.end();it++){
        if(freqS.find(it->first)!=freqS.end()){
            if(freqS[it->first] != it->second){
                return false;
            }
        }else{
            return false;
        }
    }

    return true;
    // TC = O(4n)
    // SC = O(2n)
}


// better - 2 - by using single map 
bool isAnargamBettter2(string& s , string& t){
    unordered_map<char,int> freq;

    for(auto ch : s) freq[ch]++;
    for(auto ch : t) freq[ch]--;

    for(auto pair : freq){
        if(pair.second != 0) return false;
    }


    return true;
    // TC = O(n) 
    // SC = O(n)
}

// using fixed size array intead of map -- only if lower case of upper case onnly.
bool isAnargamFunOptimal(string& s,string& t){
    vector<int> freq(26,0);

    for(auto ch : s) freq[ch-'a']++;
    for(auto ch : t) freq[ch-'a']--;

    for(auto fre : freq){
        if(fre != 0) return false;
    }

    return true;
    // TC = O(n) 
    // SC = O(1) const array of 26 char
}




int main(){
    string s = "CAT";
    string t = "TCA";

    bool isAnargam = isAnargamFunBetter(s,t);

    cout << "s = ";printString(s);
    cout << "t = ";printString(t);

    cout << "s and t are anargams : "<< isAnargam << endl;

    
    return 0;
}