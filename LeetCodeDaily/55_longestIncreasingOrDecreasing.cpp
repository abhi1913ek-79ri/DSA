#include <bits/stdc++.h>
using namespace std;

int longestMonotonicSubarray(vector<int>& nums)
{
    int n = nums.size();

    int maxLen = 1;
    int currLen = 1;

    // Strictly Increasing Subarray
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] < nums[i])
        {
            currLen++;
            maxLen = max(maxLen, currLen);
        }
        else
        {
            currLen = 1;
        }
    }

    currLen = 1;

    // Strictly Decreasing Subarray
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            currLen++;
            maxLen = max(maxLen, currLen);
        }
        else
        {
            currLen = 1;
        }
    }

    return maxLen;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << longestMonotonicSubarray(nums) << endl;

    return 0;
}