#include <bits/stdc++.h>
using namespace std;
// LC 3702 Longest Subsequence With Non-Zero Bitwise XOR
int longestSubsequence(vector<int> &nums)
{
    int n = nums.size();

    int xr = 0;
    bool hasNonZero = false;

    for (int x : nums)
    {
        xr ^= x;

        if (x != 0)
        {
            hasNonZero = true;
        }
    }

    if (xr != 0)
    {
        return n;
    }

    if (hasNonZero)
    {
        return n - 1;
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }

    cout << longestSubsequence(nums);

    return 0;
}