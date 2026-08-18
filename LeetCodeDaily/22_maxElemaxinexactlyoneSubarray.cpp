#include <bits/stdc++.h>
using namespace std;
// 3471. Find the Largest Almost Missing Integer
int largestInteger(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];

    unordered_map<int, int> freq;
    int maxElement = nums[0];
    for (auto num : nums)
    {
        freq[num]++;
        maxElement = max(maxElement, num);
    }

    if (k == 1)
    {
        int maxFreqCnt1 = -1;
        for (auto num : nums)
        {
            if (freq[num] == 1)
            {
                maxFreqCnt1 = max(maxFreqCnt1, num);
            }
        }

        return maxFreqCnt1;
    }
    if (k == n)
        return maxElement;

    int start = nums[0];
    int startCnt = freq[start];
    int end = nums[n - 1];
    int endCnt = freq[end];

    if (startCnt > 1 && endCnt > 1)
    {
        return -1;
    }
    else if (startCnt > 1)
    {
        return end;
    }
    else if (endCnt > 1)
    {
        return start;
    }

    return max(end, start);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }
    int k;
    cin >> k;

    cout << largestInteger(nums,k);
    return 0;
}