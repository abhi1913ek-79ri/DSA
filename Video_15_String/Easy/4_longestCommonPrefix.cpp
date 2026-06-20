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


string longestCommonPrefix(vector<string>& strs){
    string lcp = "";
    int i = 0;
    for(auto ch : strs[0]){
        int cnt = 0;
        for(auto &str : strs){
            if(str.length()<=i) return lcp;
            if(ch == str[i]) cnt++;
        }
        if(cnt==(strs.size())) lcp+=ch;
        else break;
        i++;
    }
    return lcp;
    // TC = N*M (worst case ) best is when the first charcarter doesnt match O(n)
    // SC = O(1)
}

// Another method - soorting and comparing first last 


string longestCommonPrefixSort(vector<string>& strs){
    sort(strs.begin(),strs.end()); // mlog(m *N) 
    string first = strs[0];
    string last = strs[strs.size()-1];
    string lcp = "";

    for(int i=0;i<first.length();i++){ // N
        if(i>last.length()-1) return lcp;
        if(first[i]==last[i]) lcp+=first[i];
        else return lcp;
    }

    return lcp;
    // TC = m*log(m*N )+N -- where m- array size and n = first string size
}

string lcpLeetCode(vector<string>& strs){
    if(strs.size() == 0) return "";
    string prefix = strs[0];
    for(int i = 0;i<strs.size();i++){
        while (strs[i].find(prefix)!=0){
            prefix = prefix.substr(0,prefix.length()-1);
            if(prefix.empty()) return "";
        }
    }
    return prefix;
}

int main(){
    vector<string> strs= {"flower","flow","flight"};
    cout<<"Strs = ";
    printArray(strs);
    string lcp = longestCommonPrefixSort(strs);
    cout << "LCP : ";
    printString(lcp);
    return 0;
}