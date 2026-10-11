#include <bits/stdc++.h>
using namespace std;
// LC-2778. Sum of Squares of Special Elements
int sumOfSquares(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (n % (i + 1) == 0)
            sum += nums[i] * nums[i];
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num:nums){
        cin >> num;
    }
    cout << sumOfSquares(nums);
    return 0;
}