#include <bits/stdc++.h>
using namespace std;
// 3090. Maximum Length Substring With Two Occurrences\

int maximumLengthSubstring(string s)
{
    int n = s.length();
    unordered_map<char, int> freq;

    int l = 0;
    int maxLen = 0;

    for (int r = 0; r < n; r++)
    { 
        freq[s[r]]++;
        while(l<=r && freq[s[r]] > 2){
            freq[s[l++]]--;
        }

        maxLen = max(maxLen,r-l+1);
    }

    return maxLen;
    // TC = O(n)
    // SC = O(26)
}

int main()
{
    string s;
    cin >> s;

    cout << maximumLengthSubstring(s);
    return 0;
}