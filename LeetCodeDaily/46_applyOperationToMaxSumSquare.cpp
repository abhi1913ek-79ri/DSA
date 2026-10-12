#include <bits/stdc++.h>
using namespace std;

// LC-2897. Apply Operations on Array to Maximize Sum of Squares

int maxSum(vector<int>& nums, int k) {
    int n = nums.size();

    long long MOD = 1000000007LL;

    // Count set bits at each position
    vector<int> countBit(32, 0);

    for (int b = 0; b < 32; b++) {
        for (auto& num : nums) {
            if (num & (1LL << b)) {
                countBit[b]++;
            }
        }
    }

    long long result = 0;

    // Construct k maximum numbers
    while (k--) {
        long long curr = 0;

        for (int b = 0; b < 32; b++) {
            if (countBit[b] > 0) {
                countBit[b]--;
                curr |= (1LL << b);
            }
        }

        result = (result + (curr * curr) % MOD) % MOD;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    cout << maxSum(nums, k) << endl;

    return 0;
}

