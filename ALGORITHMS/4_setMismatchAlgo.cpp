#include <bits/stdc++.h>
using namespace std;
// set mismatch
// Optimal - Array Manipulation - index hashing 
vector<int> findErrorNumsOptimal(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (nums[abs(nums[i]) - 1] > 0)
        {
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        else
        {
            ans.push_back(abs(nums[i]));
        }
    }

    int i = 1;
    for (auto num : nums)
    {
        if (num > 0)
            ans.push_back(i);
        i++;
    }
    return ans;
    // TC = O(2n)
    // SC = O(1)
}
int main()
{
    vector<int> nums = {1, 2, 2, 4};
    vector<int> ans = findErrorNumsOptimal(nums);
    cout << "Error  : " << ans[0] << " , " << ans[1] << endl;

    return 0;
}