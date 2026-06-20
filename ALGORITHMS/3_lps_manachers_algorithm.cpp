#include <bits/stdc++.h>
using namespace std;
// LPS - longest palindromic substring
// Input: s = "cbbd"
// Output: "bb"
// Input: s = "babad"
// Output: "bab"

// Brute Force - generate all subtsring and check for palindrome
bool isPalindrome(string &s, int l, int r)
{
    while (l <= r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
    // TC = O(n/2)
}

string longestPalindrome_brute(string s)
{
    int n = s.length();

    int l = 0;
    int r = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, i, j) && (j - i + 1) > (r - l + 1))
            {
                l = i;
                r = j;
            }
        }
    }

    return s.substr(l, r - l + 1);
    // TC = O(n^3)
    // SC = O(longestSubstr.length()) for ans
}

// optimal : manachers algorithm
// expand from center unitl palindromic
string longestPalindrome_optimal(string s)
{
    int n = s.length();
    int r = 0;
    int l = 0;


    for (int i = 0; i < n; i++)
    {
        // even length palindrom
        int c1 = i;
        int c2 = i + 1;
        while (c1 >= 0 && c2 < n && s[c1] == s[c2])
        {
            if (c2 - c1 > r - l)
            {
                l = c1;
                r = c2;
            }
            c1--;
            c2++;
        }

        // odd length palindrom
        c1 = i;
        c2 = i;
        while (c1 >= 0 && c2 < n && s[c1] == s[c2])
        {
            if (c2 - c1 > r - l)
            {
                l = c1;
                r = c2;
            }
            c1--;
            c2++;
        }
    }
    return s.substr(l,r-l+1);
    // TC = O(n*n)
    // SC = O(1)
}

int main()
{
    string s1 = "cbbd";
    string s2 = "babad";

    cout << "Input: " << s1 << endl;
    cout << "Longest Palindrome: " << longestPalindrome_brute(s1) << endl;

    cout << "\nInput: " << s2 << endl;
    cout << "Longest Palindrome: " << longestPalindrome_brute(s2) << endl;

    cout << "Input: " << s1 << endl;
    cout << "Longest Palindrome: " << longestPalindrome_optimal(s1) << endl;

    cout << "Input: " << s2 << endl;
    cout << "Longest Palindrome: " << longestPalindrome_optimal(s2) << endl;
    return 0;
}