#include <bits/stdc++.h>
using namespace std;
// 1. Single Number (LC 136)
// Every element appears twice except one.

int singleNumberIBrute(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
                cnt++;
        }
        if (cnt == 1)
            return arr[i];
    }
    // TC = O(n^2)
    // SC = O(1)
}

int singleNumberIBetter(vector<int> &arr)
{
    unordered_map<int, int> freq;
    for (auto &num : arr)
    {
        freq[num]++;
    }

    for (auto &num : arr)
    {
        if (freq[num] == 1)
            return num;
    }

    return -1;
    // TC = O(n)
    // SC = O(n)
}

int singleNumberIOptimal(vector<int> &arr)
{
    int xorAll = 0;
    for (auto &num : arr)
    {
        xorAll ^= num;
    }
    return xorAll;
    // TC = O(n)
    // SC = O(1)
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &num : nums)
        {
            cin >> num;
        }

        cout << singleNumberIBrute(nums) << "\n";
    }

    return 0;
}

/*1. Single Number (LC 136)

Every element appears twice except one.

Brute Force

Intuition: Count occurrences of every element using nested loops.

Algorithm:
For each element:
Count frequency.
If frequency==1 return it.

Time: O(n^2)    Space: O(1)

Code:

for(int i=0;i<n;i++){
int c=0;
for(int j=0;j<n;j++) if(nums[i]==nums[j]) c++;
if(c==1) return nums[i];
}

Better (Hash Map)

Intuition: Store frequencies in a map.

Algorithm:
Build frequency map.
Return key with value 1.

Time: O(n)    Space: O(n)

Code:

unordered_map<int,int> mp;
for(int x:nums) mp[x]++;
for(auto &p:mp) if(p.second==1) return p.first;

Optimal (XOR)

Intuition: Duplicates cancel because a^a=0.

Algorithm:
ans=0.
XOR all elements.
Return ans.

Time: O(n)    Space: O(1)

Code:

int ans=0;
for(int x:nums) ans^=x;
return ans;*/