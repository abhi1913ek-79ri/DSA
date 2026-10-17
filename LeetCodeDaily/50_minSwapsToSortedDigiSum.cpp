#include <bits/stdc++.h>
using namespace std;
// LC : 3551. Minimum Swaps to Sort by Digit Sum
int digiSum(int n)
{
    int sum = 0;
    while (n)
    {
        int d = n % 10;
        sum += d;
        n /= 10;
    }
    return sum;
    // TC = O(d)
    // SC = O(1)
}
int minSwaps(vector<int> &nums)
{
    int n = nums.size();
    vector<int> afterSorted(nums.begin(), nums.end());
    auto lamda = [&](int num1, int num2)
    {
        int ds1 = digiSum(num1);
        int ds2 = digiSum(num2);

        if (ds1 != ds2)
            return ds1 < ds2;
        return num1 < num2;
    };
    sort(afterSorted.begin(), afterSorted.end(), lamda);

    unordered_map<int, int> valueToIdx;
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        valueToIdx[num] = i;
    }

    int swapCnt = 0;
    for (int i = 0; i < n; i++)
    {
        int currVal = nums[i];
        int expectedVal = afterSorted[i];

        if (expectedVal == currVal)
            continue;

        int idx = valueToIdx[expectedVal];
        swapCnt++;
        swap(nums[i], nums[idx]);
        valueToIdx[expectedVal] = i;
        valueToIdx[currVal] = idx;
    }
    return swapCnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }
    cout << minSwaps(nums);
    return 0;
}