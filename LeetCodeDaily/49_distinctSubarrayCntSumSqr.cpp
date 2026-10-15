#include <bits/stdc++.h>
using namespace std;
// LC : 2913. Subarrays Distinct Element Sum of Squares I
int sumCounts(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> st;
        for (int j = i; j < n; j++)
        {
            st.insert(nums[j]);
            sum += (st.size() * st.size());
        }
    }
    return sum;
}

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }
    cout << sumCounts(nums);
    return 0;
}