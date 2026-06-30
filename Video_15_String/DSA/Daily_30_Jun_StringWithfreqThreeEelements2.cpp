#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
    int n = s.length();

    vector<int> freq(3, 0);
    int l = 0;
    int cnt = 0;

    for (int r = 0; r < n; r++) {
        freq[s[r] - 'a']++;

        while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
            cnt += (n - r);
            freq[s[l] - 'a']--;
            l++;
        }
    }

    return cnt;
}

int main() {
    string s;
    cin >> s;

    cout << solve(s) << endl;

    return 0;
}