#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Algorithm:
1. Read the number of patterns.
2. Store all patterns in a vector.
3. Read the word.
4. For every pattern:
      - Check whether it is a substring of the word
        using string::find().
      - If found, increment the answer.
5. Print the answer.

Time Complexity:
O(P * W)
P = number of patterns
W = length of word
(string::find() takes O(W) in the worst case)

Space Complexity:
O(1) (excluding input storage)
-------------------------------------------------------
*/

int solve(vector<string>& patterns, string word) {
    int cnt = 0;

    for (string &s : patterns) {
        if (word.find(s) != string::npos)
            cnt++;
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<string> patterns(n);
    for (int i = 0; i < n; i++)
        cin >> patterns[i];

    string word;
    cin >> word;

    cout << solve(patterns, word);

    return 0;
}