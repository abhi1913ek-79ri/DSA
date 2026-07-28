#include <bits/stdc++.h>
using namespace std;
// LC : 3517 smallestPalindrome
// Hashing approach
string smallestPalindrome(string s)
{
    int n = s.length();
    vector<int> freq(26,0);
    for(auto& ch : s){
        freq[ch-'a']++;
    }

    string left = "";
    string middle = "";
    for(int i=0;i<n;i++){
        if(freq[i]&1) middle += ('a' + i);
        else{
            for(int j = 0 ; j<freq[i]/2;j++){
                left += ('a'+i);
            }
        }
    }

    string right = left;
    reverse(right.begin(),right.end());

    return left + middle + right;
}

int main()
{
    string s;
    cin >> s;
    cout << smallestPalindrome(s);
    return 0;
}