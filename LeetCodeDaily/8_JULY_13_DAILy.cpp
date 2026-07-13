#include <bits/stdc++.h>
using namespace std;

// Sequential Digits
vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;

    for (int start = 1; start <= 9; start++) {
        int num = 0;

        for (int digit = start; digit <= 9; digit++) {
            num = num * 10 + digit;

            if (num > high) break;

            if (num >= low)
                ans.push_back(num);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int low, high;
        cin >> low >> high;

        vector<int> ans = sequentialDigits(low, high);

        for (int x : ans)
            cout << x << " ";
        cout << '\n';
    }

    return 0;
}