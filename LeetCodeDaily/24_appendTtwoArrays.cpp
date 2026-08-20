#include <bits/stdc++.h>
using namespace std;
// 3069. Distribute Elements Into Two Arrays I
vector<int> resultArray(vector<int> &nums)
{
    int n = nums.size();

    vector<int> arr1 = {nums[0]};
    vector<int> arr2 = {nums[1]};

    for (int i = 2; i < n; i++)
    {
        if (arr1.back() > arr2.back())
        {
            arr1.push_back(nums[i]);
        }
        else
        {
            arr2.push_back(nums[i]);
        }
    }

    arr1.insert(arr1.end(), arr2.begin(), arr2.end());

    return arr1;
}

void printArray(vector<int>& nums){
    bool flag = false;
    for(auto& num : nums){
        if(flag) cout << " ";
        cout << num;
        flag = true;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }

    vector<int> ans = resultArray(nums);

    printArray(ans);
    return 0;
}