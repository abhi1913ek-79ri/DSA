#include <bits/stdc++.h>
using namespace std;
// 1658. Minimum Operations to Reduce X to Zero
// better
int solve1(vector<int> &nums, int x)
{
    int n = nums.size();
    int sum = 0;
    for (auto &num : nums)
        sum += num;

    int target = sum - x;
    if (target < 0)
        return -1;

    unordered_map<int, int> mpp;
    mpp[0] = -1;

    int pre = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        pre += nums[i];
        int need = pre - target;

        if (mpp.find(need) != mpp.end())
        {
            maxLen = max(maxLen, i - mpp[need]);
        }
        if (mpp.find(pre) == mpp.end())
        {
            mpp[pre] = i;
        }
    }

    // maxLen == 0 only happens legitimately when target == 0
    // (keep an empty subarray, remove everything).
    // For any other target, maxLen == 0 means no valid subarray was found.
    if (maxLen == 0 && target != 0)
        return -1;

    return n - maxLen;
    // TC = O(n)
    // SC = O(n)
}

// Optimum
int solve(vector<int> &nums, int x)
{
    int n = nums.size();

    int sum = 0;
    for (auto &num : nums)
    {
        sum += num;
    }

    int target = sum - x;

    int l = 0;
    int currSum = 0;
    int maxLen = -1;
    for (int r = 0; r < n; r++)
    {
        currSum += nums[r];

        while (l <= r && currSum > target)
        {
            currSum -= nums[l++];
        }

        if (currSum == target)
        {
            maxLen = max(maxLen, r - l + 1);
        }
    }

    return maxLen == -1 ? maxLen : n - maxLen;
    // TC = O(n)
    // SC = O(1)
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &num : nums)
    {
        cin >> num;
    }

    int x;
    cin >> x;

    cout << solve1(nums, x);
    return 0;
}