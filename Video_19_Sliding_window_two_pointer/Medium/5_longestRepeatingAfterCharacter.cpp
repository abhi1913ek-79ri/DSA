#include<bits/stdc++.h>
using namespace std;
//  longest substring containing the same letter after k replacement
// can be intterpreted as longest substring having len- maxfreq <= k
int characterReplacement_brute(string s, int k){
    int n = s.length();

    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        unordered_map<char,int> freq;
        int maxFreq = 0;
        for (int j = i; j < n; j++)
        {
            freq[s[j]]++;
            maxFreq = max(maxFreq,freq[s[j]]);
            if(maxFreq >= (j-i+1-k)) maxLen = max(maxLen,j-i+1);
        }
    }
    return maxLen;
    // TC = O(n*n)
    // SC = O(26) = O(1)
}

// sliding window
int mostFrequent(unordered_map<char,int>& freq){
    int maxFreq=0;
    for(auto p : freq){
        maxFreq = max(maxFreq,p.second);
    }
    return maxFreq;
    // TC = O(26) = O(1)
    // SC = O(1)
}
int characterReplacement_optimal(string s, int k){
    int n = s.length();

    int maxLen = 0;

    int l = 0;
    unordered_map<char,int> freq;
    for (int r = 0; r < n; r++)
    {
        freq[s[r]]++;
        int maxFreq = mostFrequent(freq);
        while (maxFreq < (r-l+1-k))
        {
            freq[s[l++]]--;
        }
        maxLen = max(maxLen,r-l+1);
    }

    return maxLen;
    // TC = O(n+n)
    // SC = O(26) = O(1)
}


int characterReplacement_optimal2(string s, int k){
    int n = s.length();

    int maxLen = 0;

    int l = 0;
    unordered_map<char,int> freq;
    for (int r = 0; r < n; r++)
    {
        freq[s[r]]++;
        int maxFreq = mostFrequent(freq);
        if (maxFreq < (r-l+1-k))
        {
            freq[s[l++]]--;
        }
        maxLen = max(maxLen,r-l+1);
    }

    return maxLen;
    // TC = O(n)
    // SC = O(26) = O(1)
}

int main(){
    string s = "AABABBA";
    int k = 1;
    cout << "Longest Substring have same char : " <<characterReplacement_optimal2(s,k) << endl;
    return 0;
}