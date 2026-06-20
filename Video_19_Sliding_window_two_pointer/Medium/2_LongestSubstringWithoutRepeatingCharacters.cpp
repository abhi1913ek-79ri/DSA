#include<bits/stdc++.h>
using namespace std;
// Longest Substring Without Repeating Characters
// Problem : 
// Given a string s, find the length of the longest 
// substring without duplicate characters.

// Input: s = "abcabcbb"
// Output: 3

// Brute Force generate all substring and check for duplcacy if not found then 
// update maxLen accordingly

// O(n³) → O(n²) → O(n log n) → O(n) (set) → O(n) (map optimized)


bool containsDistinct(string s){
    set<char> st;
    for(auto ch : s){
        st.emplace(ch);
    }
    return st.size()==s.length();
}

int lengthOfLongestSubstring_brute(string s){
    int n = s.length();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if(containsDistinct(s.substr(i,j-i+1))) {
                maxLen = max(maxLen,j-i+1);
            }
        }
    }
    return maxLen;
    // TC = O(n^3)
    // SC = O(n)
}

// without substr
bool containsDistinct2(string& s,int l,int r){
    set<char> st;
    for(int i=l;i<=r;i++){
        st.emplace(s[i]);
    }
    return st.size()==(r-l+1);
    // TC = O(r-l+1)
    // SC = O(r-l+1)
}

int lengthOfLongestSubstring_brute2(string s){
    int n = s.length();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if(containsDistinct2(s,i,j)) {
                maxLen = max(maxLen,j-i+1);
            }
        }
    }
    return maxLen;
    // TC = O(n^3)
    // SC = O(n)
}


// Brute -3
int lengthOfLongestSubstring_brute3(string s){
    int n = s.length();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        set<char> st={};
        for (int j = i; j < n; j++)
        {
            st.emplace(s[j]);
            if(st.size()==j-i+1){
                maxLen = max(maxLen,j-i+1);
            }else{
                break;
            }
        }
    }
    return maxLen;
    // TC = O(n^2)
    // SC = O(n)
}


// optimal : using sliding window + set
int lengthOfLongestSubstringOptimal(string s){
    int n = s.length();
    int maxLen = 0;

    int l=0;
    
    unordered_set<char> st;
    for(int r=0;r<n;r++){
        while (st.count(s[r])&& l<=r)
        {
            st.erase(s[l]);
            l++;
        }
        st.emplace(s[r]);
        maxLen = max(maxLen,r-l+1); 
    }
    
    return maxLen;
    // TC = O(n)
    // SC = O(n)
}

// optimal2 : using sliding window + map
int lengthOfLongestSubstringOptimal2(string s){
    int n = s.length();
    int maxLen = 0;

    int l=0;
    
    unordered_map<char,int> mpp;
    for(int r=0;r<n;r++){
        if(mpp[s[r]]>=l&& l<=r)
        {
            l=mpp[s[r]]+1;
        }
        mpp[s[r]]=r;
        maxLen = max(maxLen,r-l+1); 
    }
    
    return maxLen;
    // TC = O(n)
    // SC = O(n)
}




int main(){
    string s = "abcabcbb";
    cout << "Longest substring without repeating chars : " << lengthOfLongestSubstringOptimal2(s);
    return 0;
}


// sliding window standard template
// left = 0

// for right in range(n):

//     include element at right

//     while (window invalid):
//         remove element at left
//         left++

//     update answer using (right - left + 1)


